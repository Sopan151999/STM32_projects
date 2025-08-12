/* ************************************************************************** */
/******************************************************************************
 * File Name    : Hdl_GPIO.c
 * Description  : Source file for General purpose input output
 * Author       : Sopan
 * Version      : v1.0
 * Date         : [19-06-2025]
 ******************************************************************************/

/*------------------------------------------------------------------------------
 * INCLUDES
 *----------------------------------------------------------------------------*/
#include <stdio.h>

#include "Inc/Handler/Hdl_GPIO.h"
#include "peripheral/port/plib_port.h"
#include "peripheral/eic/plib_eic.h"
#include "interrupts.h"

/*------------------------------------------------------------------------------
 * PRIVATE MACROS & DEFINITIONS
 *----------------------------------------------------------------------------*/
extern uint16_t Gbl_PA28_debaunce;

/*------------------------------------------------------------------------------
 * PRIVATE VARIABLES
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * FUNCTION DEFINITIONS
 *----------------------------------------------------------------------------*/
void Hdl_Clear_GPIO_PA15(void)
{
    GPIO_PA15_Clear();  
}

void Hdl_SET_GPIO_PA15 (void)
{
    GPIO_PA15_Set();
}
void Hdl_Toggle_GPIO_PA15 (void)
{
    GPIO_PA15_Toggle();
}



static void Hdl_callback(uintptr_t context){
    Hdl_Toggle_GPIO_PA15();
    printf("SOPAN PUSH BUTTON");
}
//void Handle_reEnable_PA28(void){
//    if( Gbl_PA28_debaunce ==20){
//       EIC_InterruptEnable(EIC_PIN_8); 
//    }
//}
void Hdl_EnableInt_GPIO_PA28(void){
    EIC_InterruptEnable(EIC_PIN_8);
}

void Hdl_Registor_Callback_PA28(void){
    EIC_CallbackRegister(EIC_PIN_8,Hdl_callback,0);
}
//EIC_InterruptHandler()
/*------------------------------------------------------------------------------
 * PRIVATE FUNCTION DEFINITIONS
 *----------------------------------------------------------------------------*/


/* *****************************************************************************
 End of File
 */


