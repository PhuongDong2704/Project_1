#ifndef LED_H
#define LED_H
#include "stm32f1xx_hal.h" 

typedef struct
{
	uint16_t ccr ;
	uint8_t light ;
	uint32_t time;
	uint32_t time_pwm;
	TIM_HandleTypeDef *htim;
	uint16_t channel;

}Led_TypeDef;

void led_onoff(Led_TypeDef *ledx,uint16_t time_blink);
void led_pwm(Led_TypeDef *ledx);
void led_init(Led_TypeDef *ledx, TIM_HandleTypeDef *htim, uint16_t channel);
#endif
