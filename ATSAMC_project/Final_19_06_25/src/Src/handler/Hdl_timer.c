/* ************************************************************************** */
/******************************************************************************
 * File Name    : Hdl_timer.c
 * Description  : Source file for Timer0
 * Author       : Sopan
 * Version      : v1.0
 * Date         : [19-06-2025]
 ******************************************************************************/

/*------------------------------------------------------------------------------
 * INCLUDES
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include "definitions.h"
#include "Inc/Handler/Hdl_timer.h"
#include "peripheral/tc/plib_tc0.h"
#include "peripheral/tcc/plib_tcc0.h"
#include "Inc/Handler/Hdl_GPIO.h"
/*------------------------------------------------------------------------------
 * PRIVATE MACROS & DEFINITIONS
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * PRIVATE VARIABLES
 *----------------------------------------------------------------------------*/
extern volatile uint16_t Gbl_500Ms;
extern volatile uint16_t gbl500Ms; 
extern volatile uint16_t Gbl_counter_1MS;
extern volatile uint16_t Gbl_counter_500Ms;
volatile uint16_t Gbl_PA28_debaunce=0;

/*------------------------------------------------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * FUNCTION DEFINITIONS
 *----------------------------------------------------------------------------*/
void TC0_1MS_Callback(TC_TIMER_STATUS status,uintptr_t context)
{
    Gbl_500Ms++;
    gbl500Ms++;
    Gbl_counter_1MS = SET;
    Gbl_PA28_debaunce++;
    if(Gbl_counter_500Ms == 500){
        Gbl_counter_500Ms=0;
        Gbl_500Ms= 1; 
       
    }else{
   
        }
}
void Hdl_Enable_Timer0 (void)
{
  // Initialization code
    TC0_TimerStart();
}

void Hdl_timer0 (void)
{
    TC0_TimerCallbackRegister(TC0_1MS_Callback,(uintptr_t) NULL);
}

void Hdl_PWM_PA8(void){
    
 TCC0_PWMStart();   
 
}

void Hdl_Set_PWM_PA8(void){
    static uint32_t lclduty =0;
    if(Gbl_500Ms ==1){
    Gbl_500Ms=0;
    lclduty =+ 50;
//    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,uint32_t lclduty);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,2160);
    if(lclduty == 2499998){
        lclduty=0;
    }
    }
}
/*------------------------------------------------------------------------------
 * PRIVATE FUNCTION DEFINITIONS
 *----------------------------------------------------------------------------*/


/* *****************************************************************************
 End of File
 */


