/*
 * Hdl_GPIO.h
 *
 *  Created on: Aug 2, 2025
 *      Author: sopan
 */

#ifndef INC_HDL_GPIO_H_
#define INC_HDL_GPIO_H_


#include "stm32f1xx_hal.h"

/*Handle gpio PA5*/
void Handle_LED_RESET(void);
/*Handle gpio PA5*/
void Handle_LED_SET(void);
/*Handle gpio PA5*/
void Handle_LED_Toggle(void);



uint8_t Handle_Read_pin(void);


#endif /* INC_HDL_GPIO_H_ */
