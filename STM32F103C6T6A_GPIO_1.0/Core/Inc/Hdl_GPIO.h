/*
 * Hdl_GPIO.h
 *
 *  Created on: Aug 2, 2025
 *      Author: sopan
 */

#ifndef INC_HDL_GPIO_H_
#define INC_HDL_GPIO_H_

#include "stm32f1xx_hal.h"


void Handle_gpio_PA5_SET(void);
void Handle_gpio_PA5_RESET(void);
void Handle_gpio_PA5_toggle(void);

uint8_t Handle_gpio_PA4_read(void);

#endif /* INC_HDL_GPIO_H_ */
