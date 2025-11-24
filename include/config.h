#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// Blynk Credentials - Replace with your actual values
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_DEVICE_NAME "Your_Device_Name"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

// WiFi Credentials - Replace with your actual values
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASS "Your_WiFi_Password"

// Pin Definitions
#define ENC_CLK 35
#define ENC_DT 34
#define ENC_SW 36
#define LIGHT_SENSOR_SDA 21
#define LIGHT_SENSOR_SCL 22
#define LED_PIN 2  // MOSFET pin for LED control
#define BUZZER_PIN 5

// Timer Constants (in seconds)
#define POMODORO_DURATION 1500  // 25 minutes
#define SHORT_BREAK_DURATION 300  // 5 minutes
#define LONG_BREAK_DURATION 900  // 15 minutes

// Global Variables
extern TFT_eSPI tft;
extern int currentBrightness;
extern bool isFocusMode;
extern int timerSeconds;
extern bool timerRunning;
extern String currentTask;
extern int manualBrightness;
extern bool manualMode;

#endif