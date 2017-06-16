#include "LPC11xx.h"                    // Device header
#include "ADC.h"                   //ADC模块

void ADC_Init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);//使能时钟
	
	LPC_IOCON->PIO1_11&=~0xBF;
	
	LPC_IOCON->PIO1_11|=0x01;//选择AD7
	
	LPC_SYSCON ->PDRUNCFG &=~(0x01<<4);//ADC模块上电
	
	LPC_SYSCON->SYSAHBCLKCTRL |=(0x01<<13);//使能ADC模块时钟
	
	LPC_ADC->CR =(0x01<<7)//选择AD7
	
	|((SystemCoreClock /1000000-1)<<8)//转换时钟1MHz
	|(0<<16)//软件控制转换操作
	|(0<<17)
	|(0<<24)//ADC转换停止
	|(0<<27);
}	
