int main (void)
{

	// �� GPIOB �˿ڵ�ʱ��
	*( unsigned int * )0x40021018 |=  ( (1) << 3 );
	
	// ����IO��PB5Ϊ��� ,�������������Ϊ10M
	*( unsigned int * )0x40010C00 &= 0xFF0FFFFF; 
	*( unsigned int * )0x40010C00 |=  0X00100000;   
	// ���� ODR �Ĵ���	
	*( unsigned int * )0x40010C0C &= ~(1<<5); //LED on
	//*( unsigned int * )0x40010C0C |= (1<<5);  //LED off
	
}


void SystemInit(void)
{
	// ������Ϊ�գ�Ŀ����Ϊ��ƭ��������������
}




