#include "Led.h" 
// Thanh ghi CCR4 = 2000 led sang nhat
// Thanh ghi CCR4 = 0 led toi nhat
void led_onoff(Led_TypeDef *ledx,uint16_t time_blink)//Ham xu li nhay led
{
	if (ledx->htim->Instance -> CCR4 !=2000)
	{
	
		if (HAL_GetTick () - ledx->time >= time_blink)
		{
			ledx->htim->Instance -> CCR4 = 2000;
			ledx->time = HAL_GetTick ();
		}
	}
	else 
	{
		if (HAL_GetTick () - ledx->time >= time_blink)
		{
			ledx->htim->Instance -> CCR4 = 0;
			ledx->time = HAL_GetTick ();
		}
	}
}
// light = 0: led tang do sang
// light = 1: led giam do sang
void led_pwm(Led_TypeDef *ledx)// Ham dieu chinh do sang led
{
	if (HAL_GetTick () - ledx->time_pwm >= 1) //Cap nhat thanh ghi CCR4 moi 1ms
	{
		if (ledx->light == 0)
		{
			ledx->ccr ++;
			if ( ledx->ccr ==2000)
			{
				ledx->light =1;
			}
		}
		else if (ledx->light ==1)
		{
			ledx->ccr --;
			if (ledx->ccr  == 0)
			{
				ledx->light = 0;
			}
		}
		ledx->htim->Instance ->CCR4 = ledx->ccr;
		ledx->time_pwm = HAL_GetTick ();
	}
}
void led_init(Led_TypeDef *ledx, TIM_HandleTypeDef *htim, uint16_t channel)//Khoi tao htim va channel cho led
{
	ledx->htim = htim;
	ledx->channel = channel ;
	HAL_TIM_PWM_Start (htim,channel);
}