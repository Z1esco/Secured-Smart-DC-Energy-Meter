# Secured Smart DC Energy Meter

A secure IoT energy monitoring project built around an ESP32 edge node, MQTT over TLS, and oneM2M integration. The system measures voltage and current, displays live readings locally, and publishes telemetry to a backend platform for remote monitoring.

## Overview

This repository contains the final project assets for a secured smart DC energy meter, including the Arduino sketch, proof-of-concept screenshots, and supporting documentation.

The implementation focuses on:

- Secure telemetry transport with MQTT over TLS.
- ESP32-based data acquisition for voltage and current monitoring.
- Local LCD feedback for on-device visibility.
- Blynk dashboard integration for remote observability.
- oneM2M/Mobius payload publishing for backend ingestion.

## Repository Structure

- [Code/](Code/) - ESP32 Arduino sketch and code-level notes.
- [Proof Of Concepts/](Proof%20Of%20Concepts/) - Dashboard and protocol evidence screenshots.
- [DFD.png](DFD.png) - Data flow diagram.
- [System Architechture Mobius.png](System%20Architechture%20Mobius.png) - System architecture diagram.
- [Hardware Components.pdf](Hardware%20Components.pdf) - Hardware reference material.
- [STRIDE Analysis.pdf](STRIDE%20Analysis.pdf) - Threat modeling notes.

## Project Status

The repository is organized for public sharing. Sensitive lab artifacts are either excluded or documented separately so credentials and other private values are not exposed in version control.

## Hardware and Software Requirements

- ESP32 development board.
- Current and voltage sensing circuitry.
- 16x2 I2C LCD.
- Wi-Fi access point.
- Blynk project and auth token.
- MQTT broker or Mobius endpoint with TLS enabled.
- Arduino IDE or PlatformIO with ESP32 support.

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
