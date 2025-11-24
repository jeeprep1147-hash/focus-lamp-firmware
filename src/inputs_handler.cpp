#include "config.h"
#include "inputs_handler.h"
#include "timer_handler.h"
#include "lamp_handler.h"

// Create Encoder Object
static AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ENC_CLK, ENC_DT, ENC_SW, -1, 4);

void IRAM_ATTR readEncoderISR() {
  rotaryEncoder.readEncoder_ISR();
}

void initInputs() {
  rotaryEncoder.begin();
  rotaryEncoder.setup(readEncoderISR);
  
  // Set boundaries: 0 to 255 (PWM range), loop = false
  rotaryEncoder.setBoundaries(0, 255, false); 
  rotaryEncoder.setEncoderValue(128); // Start at half brightness

  pinMode(ENC_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_SW), []() {
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();
    
    if (interruptTime - lastInterruptTime > 200) {  // Debounce
      if (timerRunning) {
          stopTimer();
      } else {
          startTimer(0); // Start Focus Mode
      }
      lastInterruptTime = interruptTime;
    }
  }, FALLING);
}

void handleInputs() {
  // Check if knob has been twisted
  if (rotaryEncoder.encoderChanged()) {
      
      // Get the new value (0-255) directly from the library
      manualBrightness = rotaryEncoder.readEncoder();
      
      // Enable manual mode so auto-sensor doesn't override us
      manualMode = true;
      
      // Apply brightness immediately
      setLampBrightness(manualBrightness);
      
      Serial.print("Manual Brightness: ");
      Serial.println(manualBrightness);
  }
}