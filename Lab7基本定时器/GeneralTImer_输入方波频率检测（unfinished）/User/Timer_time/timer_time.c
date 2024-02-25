#include "timer_time.h"
/********************
����NVIC��

��ʹ�ܶ�ʱ��ʱ�ӡ�
RCC_APB1PeriphClockCmd();
�� ��ʼ����ʱ��������ARR,PSC��
TIM_TimeBaseInit();
������������жϱ�־λ��������ʱ���ж�
TIM_ClearFlag
void TIM_ITConfig();

��ʹ�ܶ�ʱ����
TIM_Cmd();
�ݱ�д�жϷ�������
TIMx_IRQHandler();
*****************/

//TIM3-ETR---PD2 ��������
static void GENERAL_TIM_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);	
}


static void GENERAL_TIM__Timer_Config()
{
	 
	
	  
	// 1 ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//2 ʹ���ڲ�ʱ�ӣ�
      TIM_DeInit(TIM2);
	TIM_InternalClockConfig(TIM2);
	
		// 2 �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseStructure.TIM_Period = 2000 - 1;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
		
		// 3 �жϵ���Ӧ����
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		//����������жϱ�־λ
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	  
		//  ��������������ж�
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
		
		//4 ʹ�ܼ�����
    TIM_Cmd(TIM2, ENABLE);
}

static void GENERAL_TIM__ETRCounter_Config()
{
	
	
  	
		// 1 ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	  //2 
     TIM_DeInit(TIM3);
	//�ⲿʱ��ģʽ2����
	TIM_ETRClockMode2Config(TIM3, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00);
		  
	
		// 2 �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		
    TIM_TimeBaseStructure.TIM_Period = 0xffff - 1;

	  // ʱ��Ԥ��Ƶ��Ϊ1
    TIM_TimeBaseStructure.TIM_Prescaler= 0x00;
	
		// �˲������ã�����Ƶ ��
    TIM_TimeBaseStructure.TIM_ClockDivision=0x00;
		
		// ����������ģʽ��
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
		// �ظ���������ֵ��
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	  // ��ʼ����ʱ��
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
		
		
		//���������
	TIM_SetCounter(TIM3,0);
		// ʹ�ܼ�����
    TIM_Cmd(TIM3, ENABLE);
}

void GENERAL_TIM_Init(void)
{
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM__Timer_Config();
	GENERAL_TIM__ETRCounter_Config();

}



