#ifndef BUTTON_H
#define BUTTON_H
#include "stm32f1xx_hal.h"

typedef struct
{
	uint8_t button_current ;
	uint8_t button_later ;
	uint8_t button_filter ;
	uint8_t debouncing;
	uint8_t time_interference;
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}Button_TypeDef;

void button_handle(Button_TypeDef *buttonx);
void button_init(Button_TypeDef *buttonx, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
#endif
