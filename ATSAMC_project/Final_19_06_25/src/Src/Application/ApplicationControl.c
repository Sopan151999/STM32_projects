/*************************************************************************** */
/* ************************************************************************** */
/******************************************************************************
 * File Name    : Hdl_DAC.c
 * Description  : Source file for Digital to Analog converter
 * Author       : Sopan
 * Version      : v1.0
 * Date         : [19-06-2025]
 ******************************************************************************/

/*------------------------------------------------------------------------------
 * INCLUDES
 *----------------------------------------------------------------------------*/
#include "definitions.h"
#include"Inc/Application/Hdl_GblDATA.h"
#include "Inc/Handler/Hdl_GPIO.h"
#include "Inc/Handler/Hdl_timer.h"
#include "Inc/Handler/Hdl_DAC.h"
#include "Inc/Handler/Hdl_ADC.h"
#include "Inc/Handler/Hdl_AC.h"
/*------------------------------------------------------------------------------
 * PRIVATE MACROS & DEFINITIONS
 *----------------------------------------------------------------------------*/
//extern uint32_t Gbl_500Ms;
volatile uint16_t Gbl_500Ms=0;
volatile uint16_t Gbl_counter_1MS= RESET ;
volatile uint16_t Gbl_counter_500Ms=0;
/*------------------------------------------------------------------------------
 * PRIVATE VARIABLES
 *----------------------------------------------------------------------------*/
uint16_t ADC_count=0;
float ADC_volt=0;
/*------------------------------------------------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/
#define PB08 ADC_POSINPUT_AIN2
#define PB09 ADC_POSINPUT_AIN3
/*------------------------------------------------------------------------------
 * FUNCTION DEFINITIONS
 *----------------------------------------------------------------------------*/
//void Hdl_Enable_DAC(void)
//{
//    // Initialization code
//}

void ApplicationControl(void)
{
   
    Hdl_Enable_Timer0();
    Hdl_timer0();
    Hdl_Enable_ADC0_PA03();

     
//    Hdl_Registor_Callback_PA28();
//     Hdl_EnableInt_GPIO_PA28();
    while(1){
        if(Gbl_counter_1MS == SET){
            Gbl_counter_1MS= RESET;
//        printf("SOPAN  ");
//        Hdl_write_DAC_PA02(1022);
//             DAC_DataWrite(1022);
        Hdl_DAC_inc_by50();
        if(Gbl_500Ms>=500){
            Gbl_500Ms=0;
            Hdl_Toggle_GPIO_PA15();
        }
        ADC_count= Hdl_ADC0_PA3_result(PB09);
        ADC_volt=3.3/4095*ADC_count;
//        printf("ADC count: %f V\r\n",ADC_volt);
        
        }
          Hdl_Enable_AC();
          Hdl_registorCallback_AC();
    }
    // Periodic or polling logic
}

/*------------------------------------------------------------------------------
 * PRIVATE FUNCTION DEFINITIONS
 *----------------------------------------------------------------------------*/




/* *****************************************************************************
 End of File
 */
