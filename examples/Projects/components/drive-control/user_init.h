#ifndef  _USER_INIT_H
#define _USER_INIT_H

#include "user_can.h"
#include "user_motor.h"
#include "user_uart.h"
#include "user_pwm.h"

#include "app_gpio.h"
#include "app_wifi.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"

#include "iot_button.h"

#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_NUM_2)

extern volatile int OTA_flag;

void user_Init(void);


#endif



