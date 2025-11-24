#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// Credentials are now in platformio.ini

// Pin Definitions
#define ENC_CLK 35
#define ENC_DT 34
#define ENC_SW 36
#define LIGHT_SENSOR_SDA 21
#define LIGHT_SENSOR_SCL 22
#define LED_PIN 18  // Safe Pin (Moved from 2)
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
extern int manualBrightness;
extern bool manualMode;

// Function Prototype
void sendTimerStatusToBlynk(int minutes, int seconds, int mode);

#endif