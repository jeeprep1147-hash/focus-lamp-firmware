#ifndef CONNECTIVITY_HANDLER_H
#define CONNECTIVITY_HANDLER_H

#include "config.h"
#include <WiFi.h>

// Initialize WiFi and Blynk
void initConnectivity();

// Send timer status to Blynk
void sendTimerStatusToBlynk(int minutes, int seconds, int mode);

// Send current task to Blynk
void sendTaskToBlynk();

// Run Blynk connection
void runConnectivity();

// Blynk write function for task
void blynkWriteV3(const String& param);

#endif