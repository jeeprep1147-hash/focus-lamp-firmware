#ifndef UI_HANDLER_H
#define UI_HANDLER_H

#include "config.h"

// Initialize UI
void initUI();

// Draw main UI elements
void drawMainUI();

// Update UI with current values
void updateUI();

// Update timer display only
void updateTimerDisplay();

// Update task display only
void updateTaskDisplay();

// Update brightness display only
void updateBrightnessDisplay();

#endif