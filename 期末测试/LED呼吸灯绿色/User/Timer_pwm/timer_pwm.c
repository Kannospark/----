#include "timer_pwm.h"

//TIM3 CH1--PA6 ��������  
static void GENERAL_TIM_GPIO_Config()
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
  GPIO_Init(GPIOB, &GPIO_InitStructure);	

}


static void GENERAL_TIM__PWM_Config()
{
	
  	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	  TIM_OCInitTypeDef  TIM_OCInitStruct;
		
		// 1 ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	  
    TIM_DeInit(TIM);
	  TIM_InternalClockConfig(TIM);
	
		// 2 �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period = TIMx_Period;

	  // ʱ��Ԥ��Ƶ��Ϊ
    TIM_TimeBaseStructure.TIM_Prescaler= TIMx_Prescaler;
	
		// ʱ�ӷ�Ƶ���� ��
    TIM_TimeBaseStructure.TIM_ClockDivision=0x0;
		
		// ����������ģʽ��
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
		// �ظ���������ֵ��
		//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	  // ��ʼ����ʱ��
    TIM_TimeBaseInit(TIM, &TIM_TimeBaseStructure);
		
		//��������PWM���ܡ���ʼCCR=72
		
		TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;
		TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
		TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
		TIM_OCInitStruct.TIM_Pulse=72;		
	  TIM_OC3Init(TIM,&TIM_OCInitStruct);
		
		//ʹ��TIMx��CCR�ϵ�Ԥװ�ؼĴ���
		TIM_OC3PreloadConfig(TIM,TIM_OCPreload_Enable);
		
		//����TIMx��PWM���Ϊʹ��
		TIM_CtrlPWMOutputs(TIM,ENABLE);
		
		//ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
		TIM_ARRPreloadConfig(TIM,ENABLE);
		
		//4 ʹ��TIMx����
       TIM_Cmd(TIM, ENABLE);
}



void GENERAL_TIM_PWM_Init(void)
{
	GENERAL_TIM_GPIO_Config();
	
	GENERAL_TIM__PWM_Config();


}



