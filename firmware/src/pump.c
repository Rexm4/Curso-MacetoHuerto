#include "pump.h"

#include <freertos/FreeRTOS.h>

static gpio_num_t g_pumpPin;

void pump_init(gpio_num_t pumpPin) {
    g_pumpPin = pumpPin;
}

void pump_actuate(void) {
    gpio_set_level(g_pumpPin, 1);
    vTaskDelay(pdMS_TO_TICKS(3000));
    gpio_set_level(g_pumpPin, 0);
}
