/*
  Synapse Ledger — Sentinel Unit Firmware
  Board: ESP32-WROVER
  Description: Reads sensor data (GPS, lid status, weight, shock, NFC),
  signs it via the ATECC608B crypto co-processor, and transmits it to
  the backend server over Wi-Fi/LTE.

  TODO: Fill in pin mappings and sensor logic as hardware is finalized.
*/

#include <WiFi.h>

// ---------- Configuration ----------
const char* WIFI_SSID     = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const char* SERVER_URL    = "http://YOUR_BACKEND_URL/api/sentinel-data";

// ---------- Pin Definitions (placeholder — update per wiring) ----------
#define REED_SWITCH_PIN   4   // Lid/breach detection
#define LOAD_CELL_DOUT    16  // HX711 data
#define LOAD_CELL_SCK     17  // HX711 clock

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected.");

  // TODO: Initialize GPS module (NEO-6M)
  // TODO: Initialize MPU-6050 (shock/vibration)
  // TODO: Initialize HX711 (load cell)
  // TODO: Initialize PN532 (NFC)
  // TODO: Initialize ATECC608B (crypto signing)

  pinMode(REED_SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  // 1. Read GPS location
  // float lat, lon;
  // readGPS(lat, lon);

  // 2. Read lid/breach status
  bool isTampered = (digitalRead(REED_SWITCH_PIN) == HIGH);

  // 3. Read weight from load cell
  // float weight = readLoadCell();

  // 4. Read shock/vibration from MPU-6050
  // bool shockDetected = readShockSensor();

  // 5. Verify NFC tag
  // bool nfcValid = readNFC();

  // 6. Build data packet
  // String payload = buildPacket(lat, lon, isTampered, weight, shockDetected, nfcValid);

  // 7. Sign packet with ATECC608B
  // String signedPayload = signPacket(payload);

  // 8. Send to backend server
  // sendToServer(signedPayload);

  if (isTampered) {
    Serial.println("ALERT: Tampering detected!");
    // TODO: trigger piezo siren
  }

  delay(30000); // 30-second polling interval, per project flowchart
}
