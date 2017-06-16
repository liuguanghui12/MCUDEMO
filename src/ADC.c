#include "LPC11xx.h"                    // Device header
#include "ADC.h"                   //ADCģ��

void ADC_Init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);//ʹ��ʱ��
	
	LPC_IOCON->PIO1_11&=~0xBF;
	
	LPC_IOCON->PIO1_11|=0x01;//ѡ��AD7
	
	LPC_SYSCON ->PDRUNCFG &=~(0x01<<4);//ADCģ���ϵ�
	
	LPC_SYSCON->SYSAHBCLKCTRL |=(0x01<<13);//ʹ��ADCģ��ʱ��
	
	LPC_ADC->CR =(0x01<<7)//ѡ��AD7
	
	|((SystemCoreClock /1000000-1)<<8)//ת��ʱ��1MHz
	|(0<<16)//�������ת������
	|(0<<17)
	|(0<<24)//ADCת��ֹͣ
	|(0<<27);
}	
