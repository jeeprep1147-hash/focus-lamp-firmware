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
  rotaryEncoder.setBoundaries(0, 255, false);
  rotaryEncoder.setEncoderValue(128);

  pinMode(ENC_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_SW), []() {
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();

    if (interruptTime - lastInterruptTime > 200) {
      if (timerRunning) {
          stopTimer();
      } else {
          startTimer(0);
      }
      lastInterruptTime = interruptTime;
    }
  }, FALLING);
}

void handleInputs() {
  if (rotaryEncoder.encoderChanged()) {
      manualBrightness = rotaryEncoder.readEncoder();
      manualMode = true;
      setLampBrightness(manualBrightness);
  }
}