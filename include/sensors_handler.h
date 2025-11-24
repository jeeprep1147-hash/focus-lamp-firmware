#ifndef SENSORS_HANDLER_H
#define SENSORS_HANDLER_H

#include "config.h"
#include <Wire.h>
#include <BH1750.h>

// Initialize sensors
void initSensors();

// Handle sensor readings and auto-brightness
void handleSensors();

#endif