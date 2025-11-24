#include "config.h"
#include "lamp_handler.h"
#include "sensors_handler.h"
#include "inputs_handler.h"
#include "timer_handler.h"
#include "connectivity_handler.h"
#include "ui_handler.h"

// Global Variables
TFT_eSPI tft = TFT_eSPI();
int currentBrightness = 0;
bool isFocusMode = true;
int timerSeconds = POMODORO_DURATION;
bool timerRunning = false;
String currentTask = "No Task";
int manualBrightness = 128;
bool manualMode = false;

void setup() {
  Serial.begin(115200);
  
  // Initialize all handlers
  initLamp();
  initSensors();
  initInputs();
  initTimer();
  initConnectivity();
  initUI();
  
  // Draw initial UI
  drawMainUI();
  updateUI();
}

void loop() {
  // Handle all subsystems
  handleInputs();
  if (!manualMode) {  // Only auto-adjust brightness in auto mode
    handleSensors();
  }
  handleTimer();
  runConnectivity();
  updateUI();
}
