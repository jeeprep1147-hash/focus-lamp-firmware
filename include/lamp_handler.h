#ifndef LAMP_HANDLER_H
#define LAMP_HANDLER_H

#include "config.h"

// Initialize LED PWM and buzzer
void initLamp();

// Set lamp brightness (0-255)
void setLampBrightness(int level);

#endif
