#include "config.h"
#include "connectivity_handler.h"
#include "timer_handler.h"

void initConnectivity() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  
  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();
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

BLYNK_WRITE(V3) {
  currentTask = param.asString();
}