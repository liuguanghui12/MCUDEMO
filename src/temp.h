#ifndef __TEMP_H
#define __TEMP_H	
#include "LPC11xx.h"
#include "stdio.h"
#include "UART.h"
#include "LCD.h"

extern char  GcRcvBuf[20];

extern uint32_t temp(void);

extern void UART_SendStr(char *pucStr);

extern void LCD_P6x8Str(uint8_t  x,uint8_t y,uint8_t ch[]);

#endif
