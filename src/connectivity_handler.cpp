#include "config.h"
#include "connectivity_handler.h"
#include "timer_handler.h"
#include <BlynkSimpleEsp32.h>

void initConnectivity() {
  // Credentials from platformio.ini are automatically used here
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
}

void sendTimerStatusToBlynk(int minutes, int seconds, int mode) {
  if (Blynk.connected()) {
    Blynk.virtualWrite(V0, minutes);
    Blynk.virtualWrite(V1, seconds);
    Blynk.virtualWrite(V2, mode);
  }
}

void sendTaskToBlynk() {
  if (Blynk.connected()) {
    Blynk.virtualWrite(V3, currentTask);
  }
}

void runConnectivity() {
  Blynk.run();
}

void blynkWriteV3(const String& param) {
  currentTask = param;
}

BLYNK_WRITE(V3) {
  blynkWriteV3(param.asString());
}