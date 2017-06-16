#include "LPC11xx.h"//����ģ��
#include "UART.h"
#define UART_BPS  9600

void UART_Init(void)
{
	uint16_t usFdiv;
	LPC_SYSCON ->SYSAHBCLKCTRL |=(1<<16);//��ʱ��
	LPC_IOCON ->PIO1_6 &=~0x07;
	LPC_IOCON ->PIO1_6 |=0x01;//����ΪRXD,����
	LPC_IOCON ->PIO1_7 &=~0x07;
	LPC_IOCON ->PIO1_7 |=0x01;//����ΪTXD,����
	
	LPC_SYSCON ->SYSAHBCLKCTRL |=(1<<12);//��UARTʱ��
	LPC_SYSCON ->UARTCLKDIV =0x01;//ʱ�ӷ�ƵֵΪ1
	LPC_UART ->LCR =0x83;//8λ���䣬1λֹͣλ��0λ��żУ��λ��ʹ�ܶԳ����������ķ���
	usFdiv = (SystemCoreClock /LPC_SYSCON ->UARTCLKDIV /16)/9600 ;//���������������ֵ
	LPC_UART ->DLM =usFdiv /256;//д�����������ĸ�8λ��ֵ
	LPC_UART ->DLL =usFdiv %256;//��8λ
	LPC_UART ->LCR =0x03;//��ֹ�Գ����������ķ���
	LPC_UART ->FCR =0x07;//����FIFO
}

void UART_SendByte(uint8_t ucDat)
{
	LPC_UART -> THR = ucDat;//��������
	while((LPC_UART -> LSR & 0x40)==0);//�ȴ�������
}

void UART_SendStr(char *pucStr)
{
	while(1)
	{
		if(*pucStr == '\0')
			break;//�����������ţ��˳���
		UART_SendByte (*pucStr ++);	
	}
}

