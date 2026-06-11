# Code

This folder contains the Arduino sketch for the secured smart DC energy meter.

## Sketch

- [SmartDCMeter1.ino.ino](SmartDCMeter1.ino.ino) - ESP32 firmware for sensing, local display, Blynk updates, and MQTT publishing.

## Before You Build

Replace the following placeholders in the sketch before compiling or flashing:

- `REPLACE_WITH_BLYNK_AUTH_TOKEN`
- `REPLACE_WITH_WIFI_SSID`
- `REPLACE_WITH_WIFI_PASSWORD`

## Operational Notes

- The sketch currently uses `WiFiClientSecure::setInsecure()` for prototype testing.
- Update the TLS configuration before using the firmware in a production environment.
- Confirm the `mqttServer` IP address matches your deployment network.

## Security Notes

- Replace secrets with local-only values before building.
- Treat the sketch as a public template, not a deployment-ready credential store.