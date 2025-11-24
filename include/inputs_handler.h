#ifndef INPUTS_HANDLER_H
#define INPUTS_HANDLER_H

#include "config.h"
#include <AiEsp32RotaryEncoder.h>

// Initialize input devices
void initInputs();

// Handle input events (rotary encoder rotation and button press)
void handleInputs();

#endif