#ifndef PUMP_H__
#define PUMP_H__

#include <driver/gpio.h>

void pump_init(gpio_num_t pumpPin);
void pump_actuate(void);

#endif	//PUMP_H__