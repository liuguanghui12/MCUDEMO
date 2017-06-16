#include "LPC11xx.h"
#include "delay.h"
#include "KEY.h"
//按键模块

void  KEY_Init(void)
{
		LPC_GPIO3->DIR&=~(1<<0);//将3.0置为输入
    //LPC_GPIO3->DIR&=~(1<<1);   
}

KEY_STATUS KEY_get(void )
{
  if((LPC_GPIO3->DATA&(1<<0))==0)  	//
		{
			delay_ms(5);			  	
			if((LPC_GPIO3->DATA&(1<<0))==0)//按键3.0按下的时候
			{
				return KEY_DOWN;
			}
		}
  else return KEY_UP;		


}
