/******************************************************************************
 * File Name    : Hdl_GPIO.c
 * Description  : Source file for General purpose input output
 * Author       : Sopan
 * Version      : v1.0
 * Date         : [19-06-2025]
 ******************************************************************************/

#ifndef _HDL_GPIO_H    /* Guard against multiple inclusion */
#define _HDL_GPIO_H



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


/*------------------------------------------------------------------------------
 * INCLUDES
 *----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

/*------------------------------------------------------------------------------
 * MACROS & DEFINITIONS
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * TYPEDEFS / ENUMS / STRUCTURES
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * PUBLIC FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/
void Hdl_Clear_GPIO_PA15(void);
void Hdl_SET_GPIO_PA15(void);
void Hdl_Toggle_GPIO_PA15(void);

//static void Hdl_callback(uintptr_t context);
void Hdl_EnableInt_GPIO_PA28(void);
void Handle_reEnable_PA28(void);
void Hdl_Registor_Callback_PA28(void);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
