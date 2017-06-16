#include "LPC11xx.h"                    // Device header
#include "Delay.h"
static volatile unsigned int ticks;
void Delay(uint32_t ulTime)  
{
	uint32_t i;
	i=0;
	while(ulTime--)
	{
		for(i=0;i<6000;i++);
	}
}
void delay_ms(int ms)     //����ϵͳ���Ķ�ʱ������������ʱ
{
    SysTick->CTRL &= ~(1 << 2);      //����Ϊ�ο�ʱ�ӣ���ϵͳʱ�ӵ�һ��
    SysTick->LOAD = 20000*ms-1;            //��������ֵ
    SysTick->VAL = 0;          //����ǰ����ֵ����
    SysTick->CTRL = ((1<<1) | (1<<0));          //ʹ���жϣ��������Ķ�ʱ��
    while(!ticks);             //�ȴ���ʱʱ�䵽
    ticks = 0;             //����
    SysTick->CTRL = 0;           //ֹͣ���Ķ�ʱ��
}





