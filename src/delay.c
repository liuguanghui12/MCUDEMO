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
void delay_ms(int ms)     //利用系统节拍定时器产生毫秒延时
{
    SysTick->CTRL &= ~(1 << 2);      //设置为参考时钟，是系统时钟的一半
    SysTick->LOAD = 20000*ms-1;            //设置重载值
    SysTick->VAL = 0;          //将当前计数值清零
    SysTick->CTRL = ((1<<1) | (1<<0));          //使能中断，启动节拍定时器
    while(!ticks);             //等待定时时间到
    ticks = 0;             //清零
    SysTick->CTRL = 0;           //停止节拍定时器
}





