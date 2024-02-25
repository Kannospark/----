#include "stm32f10x.h"   
#include "led.h"
#include "Delay.h"
#include "Key.h"

int main(void)
{
	LED_GPIO_Config();
	//while(1){
	//LED_ON();
	//Delay_ms(1000);
	//LED_OFF();
	//Delay_ms(1000);
	//}
}

void Press_Key_alternate_LED(){
	LED_GPIO_Config();
	Key_Init();
	int state = 0;
	while(1)
	{
		if(Key_Scan() == 0) state = 1 - state;
		if(state == 1) LED_ON();
		else LED_OFF();
	}
}


