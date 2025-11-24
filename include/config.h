#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// Blynk Credentials
#define BLYNK_TEMPLATE_ID "TMPL3PuTM9T5R"
#define BLYNK_DEVICE_NAME "Focus Lamp"
#define BLYNK_AUTH_TOKEN "TpO2gZhZTs9GS5dUL404E3Dxd7Xp_lRh"

// WiFi Credentials
#define WIFI_SSID "SAIABODE"
#define WIFI_PASS "9963976392"

// Pin Definitions
#define ENC_CLK 35
#define ENC_DT 34
#define ENC_SW 36
#define LIGHT_SENSOR_SDA 21
#define LIGHT_SENSOR_SCL 22
#define LED_PIN 18  // Changed to 18 to avoid conflict with Screen RD pin
#define BUZZER_PIN 5

// Timer Constants
#define POMODORO_DURATION 1500
#define SHORT_BREAK_DURATION 300
#define LONG_BREAK_DURATION 900

// Global Variables
extern TFT_eSPI tft;
extern int currentBrightness;
extern bool isFocusMode;
extern int timerSeconds;
extern bool timerRunning;
extern String currentTask;

// --- THESE WERE MISSING ---
extern int manualBrightness;
extern bool manualMode;

#endif