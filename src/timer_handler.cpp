#include "config.h"
#include "timer_handler.h"
#include "ui_handler.h"
#include "connectivity_handler.h"

static unsigned long lastTimerUpdate = 0;
static int timerMode = TIMER_MODE_FOCUS;

void initTimer() {
  timerMode = TIMER_MODE_FOCUS;
  timerSeconds = POMODORO_DURATION;
  timerRunning = false;
}

void handleTimer() {
  if (!timerRunning) return;
  
  if (millis() - lastTimerUpdate >= 1000) {  // Update every second
    timerSeconds--;
    lastTimerUpdate = millis();
    
    if (timerSeconds <= 0) {
      // Timer completed
      timerRunning = false;
      // Buzz the buzzer for 1 second
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1000);
      digitalWrite(BUZZER_PIN, LOW);
      
      // Switch to break mode if coming from focus
      if (timerMode == TIMER_MODE_FOCUS) {
        timerMode = TIMER_MODE_SHORT_BREAK;
        timerSeconds = SHORT_BREAK_DURATION;
      } else {
        timerMode = TIMER_MODE_FOCUS;
        timerSeconds = POMODORO_DURATION;
      }
    }
    
    // Send updates to Blynk
    int minutes = timerSeconds / 60;
    int seconds = timerSeconds % 60;
    sendTimerStatusToBlynk(minutes, seconds, timerMode);
  }
}

void startTimer(int mode) {
  timerMode = mode;
  if (mode == TIMER_MODE_FOCUS) {
    timerSeconds = POMODORO_DURATION;
  } else if (mode == TIMER_MODE_SHORT_BREAK) {
    timerSeconds = SHORT_BREAK_DURATION;
  } else {
    timerSeconds = LONG_BREAK_DURATION;
  }
  timerRunning = true;
}

void stopTimer() {
  timerRunning = false;
}

void resetTimer() {
  if (timerMode == TIMER_MODE_FOCUS) {
    timerSeconds = POMODORO_DURATION;
  } else {
    timerSeconds = SHORT_BREAK_DURATION;  // Default to short break
  }
}

void switchTimerMode() {
  if (timerMode == TIMER_MODE_FOCUS) {
    timerMode = TIMER_MODE_SHORT_BREAK;
    timerSeconds = SHORT_BREAK_DURATION;
  } else {
    timerMode = TIMER_MODE_FOCUS;
    timerSeconds = POMODORO_DURATION;
  }
}