#include "config.h"
#include "lamp_handler.h"

void initLamp() {
  // Initialize PWM for LED control
  ledcSetup(0, 5000, 8);  // Channel 0, 5KHz, 8-bit
  ledcAttachPin(LED_PIN, 0);
  
  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  
  setLampBrightness(0);  // Start with lamp off
}

void setLampBrightness(int level) {
  if (level < 0) level = 0;
  if (level > 255) level = 255;
  
  currentBrightness = level;
  ledcWrite(0, level);
}