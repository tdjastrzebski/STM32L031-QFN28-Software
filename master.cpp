#include "master.h"

#include <stdarg.h>
#include <stdio.h>

#include "main.h"
#include "stm32l0xx_hal_tim.h"

void PreInit(void) {}

void Init(void) {}

void SysInit(void) {}

void PostInit(void) {}

void MainLoop(void) {
	static uint32_t pattern = 0xf0f0f0f0;
	static uint8_t shift = 0;

	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, (pattern >> shift) & 0x01 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	++shift %= 32;

	HAL_Delay(100);
}
