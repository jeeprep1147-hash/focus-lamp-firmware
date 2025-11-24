#include "config.h"
#include "lamp_handler.h"
#include "sensors_handler.h"

static BH1750 lightMeter;

void initSensors() {
  Wire.begin(LIGHT_SENSOR_SDA, LIGHT_SENSOR_SCL);
  lightMeter.begin();
}

void handleSensors() {
  if (manualMode) return;  // Don't auto-adjust when in manual mode
  
  float lux = lightMeter.readLightLevel();
  
  // Map lux to brightness level (0-255)
  int autoBrightness = map(constrain(lux, 0, 1000), 0, 1000, 20, 255);
  
  setLampBrightness(autoBrightness);
}