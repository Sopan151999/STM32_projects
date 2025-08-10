/*
 * ApplicationControl.c
 *
 *  Created on: Aug 5, 2025
 *      Author: sopan
 */


#include "Hdl_CAN.h"
//void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
//{
//    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &RxHeader, RxData);
//    CAN_MessageReceived = 1;  // Flag set for main loop
//}
int ApplicationControl(void)
{
//    HAL_Init();
//    SystemClock_Config();
//    MX_GPIO_Init();
//    MX_CAN_Init();
//	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO1_MSG_PENDING);
	STM_Msg_0x600.PWM_data =0;
	STM_Msg_0x600.plm_data =0;
    CAN_Init();  // Start CAN + filters + IRQs

    uint8_t msg[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    CAN_Send(0x123, msg, 8);

    while (1)
    {
    	STM_Msg_0x600.PWM_data ++;
    	STM_Msg_0x600.plm_data ++;
        if (CAN_MessageReceived) {
            CAN_MessageReceived = 0;

            // Example: Echo received byte to LED or Serial
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        }
        CAN_Send(0x123, msg, 8);
        Handle_CAN_TX();
        HAL_Delay(10);
    }
}
