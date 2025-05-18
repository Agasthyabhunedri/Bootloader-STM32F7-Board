#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f7xx_hal.h"

void SystemClock_Config(void);
int receive_and_flash_firmware(void);

#endif