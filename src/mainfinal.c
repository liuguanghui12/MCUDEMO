#include "LPC11xx.h"         // Device header
#include "ADC.h"
#include <stdio.h>
#include <string.h>
#include "KEY.h"
#include "UART.h"
#include "LCD.h"
#include "temp.h"


int main (void)
{

	  ADC_Init();
	  KEY_Init();
	  UART_Init();
	  LCD_Init();

	while(1)	
	{
		
	temp();	

	  LCD_DisplayStr(0,0,GcRcvBuf);
					
	}
}
