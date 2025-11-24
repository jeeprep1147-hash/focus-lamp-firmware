#include "config.h"
#include "inputs_handler.h"
#include "timer_handler.h"
#include "lamp_handler.h"

static AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ENC_CLK, ENC_DT, ENC_SW, -1, 4);

void IRAM_ATTR readEncoderISR() {
  rotaryEncoder.readEncoder_ISR();
}

void initInputs() {
  rotaryEncoder.begin();
  rotaryEncoder.setup(readEncoderISR);
  pinMode(ENC_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_SW), []() {
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();
    
    if (interruptTime - lastInterruptTime > 200) {  // Debounce
      timerRunning = !timerRunning;  // Toggle timer
      lastInterruptTime = interruptTime;
    }
  }, FALLING);
}

void handleInputs() {
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 50) {  // Update at 20Hz
    int encoderDelta = rotaryEncoder.encoderChangedValue();
    
    if (encoderDelta != 0) {
      manualMode = true;
      
      // Adjust brightness with encoder
      manualBrightness += encoderDelta;
      if (manualBrightness < 0) manualBrightness = 0;
      if (manualBrightness > 255) manualBrightness = 255;
      
      setLampBrightness(manualBrightness);
      
      rotaryEncoder.setEncoderValue(manualBrightness);
    }
    lastUpdate = millis();
  }
}