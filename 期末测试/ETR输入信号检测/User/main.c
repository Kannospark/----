/*********************************
оƬ��STM32F103ZET6
ʵ�ֹ��ܣ�TIM2��ʱ200ms��TIM3ʹ���ⲿETR������Ϊ������м�����
���ţ�TIM3 ETR---PD2
*************************************/

#include "stm32f10x.h" 
#include "timer_time.h"
#include "usart.h"

float Frequency_value;

int main(void)
{
	
	 
	  // �����ж���Ϊ0
      NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	
	  GENERAL_TIM_Init();  
	  USART_Config();  
	 
	
	  while(1)
		{
				 Usart_SendString( DEBUG_USARTx,"\nHello!\n");
				 printf("Frequency of the input signal is \n%f\r",Frequency_value);
	  }
}






