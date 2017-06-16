#include "LPC11xx.h"
#include "delay.h"
#include "KEY.h"
//����ģ��

void  KEY_Init(void)
{
		LPC_GPIO3->DIR&=~(1<<0);//��3.0��Ϊ����
    //LPC_GPIO3->DIR&=~(1<<1);   
}

KEY_STATUS KEY_get(void )
{
  if((LPC_GPIO3->DATA&(1<<0))==0)  	//
		{
			delay_ms(5);			  	
			if((LPC_GPIO3->DATA&(1<<0))==0)//����3.0���µ�ʱ��
			{
				return KEY_DOWN;
			}
		}
  else return KEY_UP;		


}
