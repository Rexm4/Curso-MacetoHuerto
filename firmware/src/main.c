#include <freertos/FreeRTOS.h>
#include "comms.h"
#include "pump.h"
#include "scanneri2c.h"
#include "sensors.h"
#include "system.h"
#include "esp_log.h"

void app_main() {

  /*
  while (1) {
    scanner_scan();
    vTaskDelay(pdMS_TO_TICKS(1000));
  }*/

  vTaskDelay(pdMS_TO_TICKS(3000));

  SystemDevs* sysDevs = system_init();

  SensorConfig sensorsconfig;
  sensorsconfig.bmeDev = sysDevs->bme;
  sensorsconfig.adsDev = sysDevs->ads;
  sensors_init(&sensorsconfig);
  pump_init(sysDevs->pumpPin);

  SensorData data;
  for (;;) {
    sensors_update(&data);

    printf("LUZ: %2.4f | HUM: %2.4f | P: %2.2f | H: %2.2f | T: %2.2f\n", data.adcLDR,
           data.adcHumidity, data.bme.pressure, data.bme.humidity, data.bme.airTemp);
    //..

    comms_send();

    // Actuate pump if humidity is low
    if (data.adcHumidity < 20.0f) {
      ESP_LOGI("PUMP", "Actuating pump...");
      pump_actuate();
      ESP_LOGI("PUMP", "Pump actuation complete.");
    }

    system_sleep();

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}