#include "GeneralTim.h"

// ��ʱ�����벶���û��Զ�������ṹ�嶨��
TIM_ICUserValueTypeDef TIM_ICUserValueStructure = {0,0,0,0};


static void GENERAL_TIM_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // ���벶��ͨ�� GPIO ��ʼ��  TIM5  ��PA0 �˿�
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);	
}


static void GENERAL_TIM_Mode_Config(void)
{
	  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/	
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_PERIOD;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_PSC;	
	// ʱ�ӷ�Ƶ���ӣ�����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

	/*--------------------���벶��ṹ���ʼ��-------------------*/	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	// �������벶���ͨ������Ҫ���ݾ����GPIO������
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	// ���벶���źŵļ�������
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	// ����ͨ���Ͳ���ͨ����ӳ���ϵ����ֱ���ͷ�ֱ������
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// �������Ҫ��������źŵķ�Ƶϵ��
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// �������Ҫ��������źŵ��˲�ϵ��
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// ��ʱ�����벶���ʼ��
	TIM_ICInit(TIM5, &TIM_ICInitStructure);
	/*--------------------�ж�����-------------------*/	
	//NVIC ����
	 NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn ;	
		// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  // ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
	// ������ºͲ����жϱ�־λ
    TIM_ClearFlag(TIM5, TIM_FLAG_Update | TIM_FLAG_CC1);	
    // �������ºͲ����ж�  
	TIM_ITConfig (TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE );
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM5, ENABLE);
}

void GENERAL_TIM_Init(void)
{
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM_Mode_Config();
}
