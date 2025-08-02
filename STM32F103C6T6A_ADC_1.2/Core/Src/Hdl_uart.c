/*
 * Hdl_uart.c
 *
 *  Created on: Aug 3, 2025
 *      Author: sopan
 */

#include<Hdl_uart.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


extern UART_HandleTypeDef huart1;  // Ensure this is defined somewhere
/*
 int adc_val = 1023;
float temp = 36.5;
char *name = "Sopan";

UART_Print("ADC = %d, Temp = %.2f, Name = %s\r\n", adc_val, temp, name);
 */
void Handle_UART_Print(const char *format, ...) {
    char buffer[100];  // Adjust size as needed
    va_list args;
    va_start(args, format);
    int len = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (len > 0) {
        HAL_UART_Transmit(&huart1, (uint8_t*)buffer, len, 100);
    }
}
