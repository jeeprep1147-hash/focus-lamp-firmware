#include "config.h"
#include "lamp_handler.h"
#include "sensors_handler.h"
#include "inputs_handler.h"
#include "timer_handler.h"
#include "connectivity_handler.h"
#include "ui_handler.h"

// Global Variables Definition
TFT_eSPI tft = TFT_eSPI();
int currentBrightness = 0;
bool isFocusMode = true;
int timerSeconds = POMODORO_DURATION;
bool timerRunning = false;
String currentTask = "No Task";

// --- THESE WERE MISSING ---
int manualBrightness = 128;
bool manualMode = false;

void setup() {
  Serial.begin(115200);
  
  initLamp();
  initSensors();
  initInputs();
  initTimer();
  initConnectivity();
  initUI();
  
  drawMainUI();
  updateUI();
}

void loop() {
  handleInputs();
  
  // Only run auto-brightness if user hasn't taken manual control
  if (!manualMode) {  
    handleSensors();
  }
  
  handleTimer();
  runConnectivity();
  updateUI();
}
