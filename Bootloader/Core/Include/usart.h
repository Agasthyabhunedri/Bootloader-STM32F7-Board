#ifndef __USART_H
#define __USART_H

#include "stm32f7xx_hal.h"

void MX_USART2_UART_Init(void);
int UART_Receive(uint8_t* buffer, uint32_t len);

#endif