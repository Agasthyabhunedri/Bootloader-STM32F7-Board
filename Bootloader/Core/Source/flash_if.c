#include "flash_if.h"
#include "usart.h"

#define APP_ADDRESS 0x08008000
#define PAGE_SIZE   0x4000
#define NUM_PAGES   2

int receive_and_flash_firmware(void) {
    uint8_t buffer[256];
    HAL_FLASH_Unlock();

    for (int i = 0; i < NUM_PAGES; ++i) {
        FLASH_Erase_Sector(FLASH_SECTOR_2 + i, VOLTAGE_RANGE_3);
    }

    uint32_t address = APP_ADDRESS;
    while (1) {
        int status = UART_Receive(buffer, sizeof(buffer));
        if (status != HAL_OK) break;
        for (int i = 0; i < sizeof(buffer); i += 4) {
            uint32_t word = *(uint32_t*)&buffer[i];
            HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, word);
            address += 4;
        }
        if (address >= APP_ADDRESS + PAGE_SIZE * NUM_PAGES) break;
    }

    HAL_FLASH_Lock();
    return 1;
}