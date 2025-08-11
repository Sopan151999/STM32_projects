/*
 * ApplicationControl.c
 *
 *  Created on: Aug 5, 2025
 *      Author: sopan
 */

#include"globel_data.h"
char buffer[16];
int ApplicationControl(void)
{

	STM_Msg_0x600.PWM_data =0;
	STM_Msg_0x600.plm_data =0;
	STM_Msg_0x201.Anurag_age =21;
	STM_Msg_0x201.Anurag_marks =99;
	STM_Msg_0x201.AnuragPhNo5Dig = 73783 - 9000;
	STM_Msg_0x201.AnuragPhNo05Dig= 95844 - 90000;
	STM_Msg_0x201.AnuragID = 45625;
	STM_Msg_0x102.myPhoneNo = 7378395844;



    CAN_Init();  // Start CAN + filters + IRQs
    SSD1306_Init();
    uint8_t msg[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    CAN_Send(0x123, msg, 8);

    SSD1306_GotoXY (0,0);
    SSD1306_Puts ("SOPAN", &Font_11x18, 1);
    SSD1306_GotoXY (0, 30);
    SSD1306_Puts ("DHAYE", &Font_11x18, 1);
    SSD1306_UpdateScreen();
    HAL_Delay (1000);
    SSD1306_Clear();

    while (1)
    {
    	STM_Msg_0x600.PWM_data ++;
    	STM_Msg_0x600.plm_data ++;
    	Handle_control_IO();

        SSD1306_GotoXY (0,0);
    	sprintf(buffer, "Val1: %-3d", STM_Msg_0x301.gfx_Val);
    	SSD1306_Puts (buffer, &Font_11x18, 1);
    	memset(buffer, 0, sizeof(buffer));
    	sprintf(buffer, "Val1:%-3d", STM_Msg_0x301.gfx_val2);
    	SSD1306_GotoXY (0, 30);
    	SSD1306_Puts (buffer, &Font_11x18, 1);
    	SSD1306_UpdateScreen();
//    	SSD1306_Clear();

        CAN_Send(0x123, msg, 8);
        Handle_CAN_TX();
        HAL_Delay(10);
    }
}
