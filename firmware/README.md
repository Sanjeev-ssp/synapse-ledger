# Firmware — Sentinel Unit

ESP32-WROVER firmware for the Sentinel Unit. Written in C/C++ using the Arduino IDE.

## Hardware
- ESP32-WROVER (main controller)
- ATECC608B (cryptographic signing)
- NEO-6M GPS module
- SIM A7672S LTE module
- MPU-6050 (shock/vibration)
- Magnetic reed switch (lid/breach detection)
- HX711 + load cell (weight monitoring)
- PN532 NFC reader
- Conductive mesh (breach detection)

## Setup
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) and add ESP32 board support.
2. Install required libraries: `TinyGPSPlus`, `HX711`, `Adafruit_PN532`, `ArduinoJson`.
3. Open `sentinel_unit/sentinel_unit.ino`, update Wi-Fi credentials and server URL.
4. Select **ESP32 Wrover Module** as the board, then upload.

## Status
🚧 Skeleton — sensor read/write logic to be implemented as hardware integration progresses.
