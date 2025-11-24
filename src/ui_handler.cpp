#include "config.h"
#include "ui_handler.h"

static int lastTimerMinutes = -1;
static int lastTimerSeconds = -1;
static String lastTask = "";
static int lastBrightness = -1;

void initUI() {
  tft.init();
  tft.setRotation(1);  // Landscape mode
  tft.fillScreen(TFT_BLACK);
}

void drawMainUI() {
  tft.fillScreen(TFT_BLACK);
  
  // Title
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.drawString("FOCUS LAMP", 10, 10);
  
  // Timer display area
  tft.drawRect(50, 60, 220, 80, TFT_WHITE);
  tft.setTextSize(3);
  
  // Task display
  tft.drawRect(20, 160, 280, 60, TFT_BLUE);
  tft.setTextSize(1);
  tft.setTextColor(TFT_CYAN);
  tft.drawString("TASK:", 25, 165);
  
  // Brightness display
  tft.drawRect(20, 240, 280, 40, TFT_GREEN);
  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("BRIGHT:", 25, 245);
  
  // Mode indicator
  tft.setTextSize(1);
  tft.setTextColor(TFT_RED);
  tft.drawString("MODE: FOCUS", 20, 300);
}

void updateUI() {
  updateTimerDisplay();
  updateTaskDisplay();
  updateBrightnessDisplay();
}

void updateTimerDisplay() {
  int minutes = timerSeconds / 60;
  int seconds = timerSeconds % 60;
  
  if (minutes != lastTimerMinutes || seconds != lastTimerSeconds) {
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.fillRect(60, 70, 200, 60, TFT_BLACK);
    
    char timeStr[10];
    sprintf(timeStr, "%02d:%02d", minutes, seconds);
    tft.drawString(timeStr, 90, 85);
    
    lastTimerMinutes = minutes;
    lastTimerSeconds = seconds;
  }
  
  // Update mode indicator
  tft.fillRect(20, 300, 150, 20, TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(TFT_RED);
  if (isFocusMode) {
    tft.drawString("MODE: FOCUS", 20, 300);
  } else {
    tft.drawString("MODE: BREAK", 20, 300);
  }
}

void updateTaskDisplay() {
  if (currentTask != lastTask) {
    tft.setTextSize(1);
    tft.setTextColor(TFT_CYAN);
    tft.fillRect(25, 185, 270, 30, TFT_BLACK);
    tft.drawString(currentTask, 25, 190, 2);  // Using text wrapping font 2
    
    lastTask = currentTask;
  }
}

void updateBrightnessDisplay() {
  int brightness = manualMode ? manualBrightness : currentBrightness;
  
  if (brightness != lastBrightness) {
    tft.setTextSize(1);
    tft.setTextColor(TFT_YELLOW);
    tft.fillRect(90, 245, 200, 20, TFT_BLACK);
    
    char brightStr[10];
    sprintf(brightStr, "%d/255", brightness);
    tft.drawString(brightStr, 90, 245);
    
    lastBrightness = brightness;
  }
}