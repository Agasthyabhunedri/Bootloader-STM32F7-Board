# STM32F7 Bootloader Project

This repository contains a simple yet functional bootloader for the STM32F7 series microcontrollers, built using STM32CubeIDE. The bootloader allows firmware updates over UART and jumps to the main application after verification.

## 📁 Project Structure

```
STM32F7-Bootloader/
├── Bootloader/
│   ├── Core/
│   │   ├── Src/
│   │   │   ├── main.c
│   │   │   ├── stm32f7xx_it.c
│   │   │   ├── usart.c
│   │   │   └── flash_if.c
│   │   └── Inc/
│   │       ├── main.h
│   │       ├── usart.h
│   │       └── flash_if.h
│   └── STM32CubeIDE project files
├── Application/
│   └── Similar structure, with application code
└── README.md
```

---

## 🚀 Bootloader Design

### Flash Memory Layout:
- **Bootloader**:  `0x08000000` to `0x08007FFF`
- **Application**: `0x08008000` to end of flash

### Interfaces:
- **UART**: Used to receive binary firmware images
- **FLASH**: Application is stored starting at `0x08008000`

---
