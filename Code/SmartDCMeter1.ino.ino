#define BLYNK_TEMPLATE_ID "TMPL61nAh6nLY"
#define BLYNK_TEMPLATE_NAME "Secure Smart DC Energy Meter"
#define BLYNK_AUTH_TOKEN "REPLACE_WITH_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClientSecure.h> // Upgraded for TLS/SSL requirement
#include <BlynkSimpleEsp32.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "REPLACE_WITH_WIFI_SSID";
char pass[] = "REPLACE_WITH_WIFI_PASSWORD";

// Windows IP for Mobius/Mosquitto
// REPLACE THIS WITH YOUR ACTUAL WINDOWS IPV4 ADDRESS
const char* mqttServer = "192.168.137.1"; 
const int mqttPort = 8883; // Upgraded to MQTTS Secure Port
const char* mqttTopic = "/oneM2M/req/SOrigin/Mobius2/json";

WiFiClientSecure espClient; // Uses TLS 1.2
PubSubClient mqttClient(espClient);
LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

#define VOLTAGE_PIN 35
#define CURRENT_PIN 34
#define SDA_PIN 21
#define SCL_PIN 22

void reconnectMQTT() {
  if (!mqttClient.connected()) {
    Serial.print("Connecting to Secure MQTT...");
    String clientId = "ESP32Client-" + String(random(0xffff), HEX);
    
    if (mqttClient.connect(clientId.c_str())) {
      Serial.println("Secure Connection Established");
    } else {
      Serial.print("Failed, rc=");
      Serial.println(mqttClient.state());
    }
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  lcd.init();
  lcd.backlight();
  lcd.print("Securing Network");
  
  // Bypass local cert verification for prototype testing
  espClient.setInsecure(); 
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  mqttClient.setServer(mqttServer, mqttPort);

  lcd.clear();
  lcd.print("System Secured");
  delay(1500);
  lcd.clear();
  
  timer.setInterval(2000L, processAndSendData);
}

void processAndSendData() {
  if (!mqttClient.connected()) {
    reconnectMQTT();
  }
  mqttClient.loop();

  int rawVoltage = analogRead(VOLTAGE_PIN);
  int rawCurrent = analogRead(CURRENT_PIN);

  float voltSignal = (rawVoltage / 4095.0) * 3.3;
  float currentSignal = (rawCurrent / 4095.0) * 3.3;

  float calcVoltage = voltSignal * 5.0;
  float calcCurrent = abs((currentSignal - 2.5) / 0.185);

  if (calcCurrent < 0.05) {
    calcCurrent = 0.0;
  }

  lcd.setCursor(0, 0);
  lcd.print("Volt: "); lcd.print(calcVoltage, 2); lcd.print(" V  ");
  lcd.setCursor(0, 1);
  lcd.print("Curr: "); lcd.print(calcCurrent, 2); lcd.print(" A  ");

  Blynk.virtualWrite(V0, calcVoltage);
  Blynk.virtualWrite(V1, calcCurrent);

  if (mqttClient.connected()) {
    String payload = "{\"m2m:rqp\":{\"op\":1,\"to\":\"/Mobius/SecureMeter/SensorData\",\"fr\":\"SOrigin\",\"rqi\":\"m_rqi" + String(millis()) + "\",\"ty\":4,\"pc\":{\"m2m:cin\":{\"con\":\"{\\\"voltage\\\":" + String(calcVoltage) + ",\\\"current\\\":" + String(calcCurrent) + "}\"}}}}";
    mqttClient.publish(mqttTopic, payload.c_str());
  }
}

void loop() {
  Blynk.run();
  timer.run(); 
}