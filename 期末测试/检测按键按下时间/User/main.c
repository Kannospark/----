/*********************************
оƬ��STM32F103VET6
ʵ�ֹ��ܣ�����ʹ��TIM5������������Ĳ�������ͨ�����ڴ�ӡ����
���ţ�PA0�������GeneralTim.c�ĵ�����
*************************************/

#include "stm32f10x.h" 
#include "usart.h"
#include "GeneralTim.h"

 uint32_t number; 
int main(void)
{
	// uint32_t number; 
	// TIM ������������ʱ��
	 uint32_t TIM_PscCLK = 72000000 / (GENERAL_TIM_PSC+1);
	// �����ж���Ϊ0
      NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    //��ʼ����ʱ���ʹ���
	  GENERAL_TIM_Init();  
	  USART_Config();  
	
	  printf ( "\r\n���Ӵ���ʵ�� STM32 ���벶��ʵ��\r\n" );
	  printf ( "\r\n����K1������K1���µ�ʱ��\r\n" );
	
	while ( 1 )
	{
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// ����ߵ�ƽʱ��ļ�������ֵ
			number = TIM_ICUserValueStructure.Capture_Period * (GENERAL_TIM_PERIOD+1) + 
			       (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
			// ��ӡ�ߵ�ƽ����ʱ��  //����������������õ��Ļ������͡���
			//printf ( "\r\n��øߵ�ƽ����ʱ�䣺%d.%d s\r\n",number/TIM_PscCLK,number%TIM_PscCLK );
			printf ( "\r\n��øߵ�ƽ����ʱ�䣺%f s\r\n",(float)number/TIM_PscCLK);
			
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;			
		}		
	}
	
}






