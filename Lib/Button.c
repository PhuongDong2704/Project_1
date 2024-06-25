#include "Button.h" 

__weak void button_press(Button_TypeDef *buttonx)//Ham xu li khi nhan nut
{
}
__weak void button_release(Button_TypeDef *buttonx)//Ham xu li khi nha nut
{
}

void button_handle (Button_TypeDef *buttonx)
{
	// -------------------------LOC NHIEU-------------------------------------
	uint8_t state_button = HAL_GPIO_ReadPin (buttonx->GPIOx, buttonx->GPIO_Pin);//Doc chan nut bam
	if (buttonx->button_filter != state_button )
	{
		buttonx->button_filter = state_button ;
		buttonx->debouncing = 1;
		buttonx->time_interference = HAL_GetTick();
	}
	// -------------------------XAC LAP TRANG THAI----------------------------
	if (buttonx->debouncing && (HAL_GetTick() - buttonx->time_interference >= 50))
	{
		buttonx->button_current = buttonx->button_filter ;//Trang thai nut bam duoc xac lap
		buttonx->debouncing = 0;	
	}
	// -------------------------XU LI TIN HIEU--------------------------------
	if (buttonx->button_current != buttonx->button_later )
	{
		if (buttonx->button_current == 0)
		{
			button_press(buttonx);
		}
		else
		{
			button_release(buttonx);
		}
		buttonx->button_later = buttonx->button_current;
	}
}
void button_init(Button_TypeDef *buttonx, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)//Khoi tao chan cho button
{
	buttonx->GPIOx = GPIOx;
	buttonx->GPIO_Pin = GPIO_Pin;
}