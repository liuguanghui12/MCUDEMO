#ifndef __LCD_H
#define __LCD_H
#include "LPC11xx.h"                   
extern void Delayus(uint16_t ms);

extern void Delayms(uint16_t ms);

extern void SysTick_Handler(void);

uint8_t Busy_Check(void);

extern void LCD_WriteCommand(uint32_t cmd);

extern void LCD_WriteData(uint32_t dat);

uint8_t LCD_DisplayChar(uint8_t x, uint8_t y, uint8_t ch);

uint8_t LCD_DisplayStr(uint8_t x, uint8_t y, uint8_t *pStr);

extern void LCD_IOInit(void);

extern void LCD_Init(void);

#endif
