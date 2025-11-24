#ifndef TIMER_HANDLER_H
#define TIMER_HANDLER_H

#include "config.h"

// Timer modes
#define TIMER_MODE_FOCUS 0
#define TIMER_MODE_SHORT_BREAK 1
#define TIMER_MODE_LONG_BREAK 2

// Initialize timer
void initTimer();

// Handle timer countdown
void handleTimer();

// Start the current timer
void startTimer(int mode);

// Stop the current timer
void stopTimer();

// Reset timer to appropriate duration based on mode
void resetTimer();

// Switch between focus and break modes
void switchTimerMode();

#endif