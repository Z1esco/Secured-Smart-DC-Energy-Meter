# Secured Smart DC Energy Meter

<p align="center">
	<img src="https://img.shields.io/badge/ESP32-IoT%20Edge%20Device-1f7a8c?style=for-the-badge" alt="ESP32 badge" />
	<img src="https://img.shields.io/badge/MQTT-TLS%20Protected-0f766e?style=for-the-badge" alt="MQTT over TLS badge" />
	<img src="https://img.shields.io/badge/oneM2M-Mobius%20Integration-334155?style=for-the-badge" alt="oneM2M badge" />
</p>

<p align="center">
	A secure IoT energy monitoring project that measures DC voltage and current on an ESP32, displays live readings locally, and publishes telemetry to Blynk and a oneM2M/Mobius backend.
</p>

## Project Snapshot

<table>
	<tr>
		<td><strong>Purpose</strong><br />Securely monitor DC energy usage and publish telemetry over encrypted channels.</td>
		<td><strong>Core Flow</strong><br />Sense voltage/current → display locally → send to cloud/backend → review telemetry.</td>
		<td><strong>Security Focus</strong><br />TLS transport, credential hygiene, and safer public sharing of project assets.</td>
	</tr>
</table>

## Highlights

- ESP32-based sensing and telemetry.
- Local 16x2 LCD feedback for live readings.
- Blynk dashboard support for remote monitoring.
- MQTT over TLS for protected data transport.
- oneM2M/Mobius payload publishing for backend integration.
- Supporting documentation for architecture, STRIDE analysis, hardware, and proof-of-concept evidence.

## Technology Stack

| Category | Technologies / Tools |
| --- | --- |
| Language | Arduino C++ for ESP32 firmware |
| Embedded Platform | ESP32 development board |
| Networking | Wi-Fi, MQTT, TLS/SSL |
| IoT / Cloud | Blynk, oneM2M, Mobius |
| UI / Display | 16x2 I2C LCD |
| Libraries | `WiFi.h`, `WiFiClientSecure.h`, `BlynkSimpleEsp32.h`, `PubSubClient.h`, `Wire.h`, `LiquidCrystal_I2C.h` |
| Development Tools | Arduino IDE or PlatformIO |
| Analysis / Evidence | Packet capture, STRIDE model, architecture and hardware documentation |

## Hardware Used

- ESP32 development board.
- Voltage sensing circuit.
- Current sensing circuit.
- 16x2 I2C LCD.
- Wi-Fi network access.
- Backend endpoint or MQTT broker with TLS support.

## Software Used

- Arduino IDE or PlatformIO.
- Blynk platform for dashboard and virtual pin updates.
- MQTT broker or Mobius endpoint.
- TLS-enabled network stack on the ESP32.
- Project documentation files for threat modeling, architecture, and hardware references.

## Repository Structure

| Path | Description |
| --- | --- |
| [Code/](Code/) | ESP32 sketch and code-level notes. |
| [Proof Of Concepts/](Proof%20Of%20Concepts/) | Dashboard and protocol evidence screenshots. |
| [DFD.png](DFD.png) | Data flow diagram. |
| [System Architechture Mobius.png](System%20Architechture%20Mobius.png) | System architecture diagram. |
| [Hardware Components.pdf](Hardware%20Components.pdf) | Hardware reference material. |
| [STRIDE Analysis.pdf](STRIDE%20Analysis.pdf) | Threat modeling notes. |

## Setup

1. Open the sketch in [Code/SmartDCMeter1.ino.ino](Code/SmartDCMeter1.ino.ino).
2. Replace the placeholder Wi-Fi SSID, Wi-Fi password, and Blynk auth token with your own values.
3. Update the MQTT server address if your broker is not running on the same network.
4. Review the TLS settings before deployment. The current sketch uses `setInsecure()` for prototype testing only.
5. Flash the sketch to the ESP32 and verify the LCD, Blynk, and MQTT outputs.

## Security Notes

- Do not commit real credentials to the repository.
- Prefer a certificate-pinned or CA-validated TLS configuration for production use.
- Treat the proof-of-concept screenshots as sensitive lab evidence.
- Avoid committing raw packet captures or credential-bearing exports to the public repository.

## Notes

This project is organized as an academic security demonstration. Some values in the sketch are intentionally left as placeholders so the repository can be shared safely.
