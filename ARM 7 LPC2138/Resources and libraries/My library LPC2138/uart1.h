/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 10 July, 2017
 * Note(s): Cclk=12MHz
						Pclk=60MHz
						Baud rate = 9600
 *----------------------------------------------------------------------------*/

#include<lpc213x.h>
#include"PLL.h"

#ifndef __uart1_h
#define __uart1_h

#define THRE (1<<5) // Transmit Holding Register Empty
#define RDR (1<<0) // Receiver Data Ready
#define MULVAL 1
#define DIVADDVAL 0
#define NEW_LINE 0xA // ASCII code for new line
#define ENTER 0xD // ASCII code for Enter
#define ECHO 1		// echo on off

void init_uart1()
{
	PINSEL0 = 0x50000;  // pin collect block to function as UART
  U1LCR	= 3 | (1<<7) ; // 8 bits, no Parity, 1 Stop bit | set DLAB = 1  
  U1DLM = 1;
	U1DLL	= 135;	// value for 9600. see UART calculations
  U1FDR = (MULVAL<<4) | DIVADDVAL;  
  U1LCR &= 0x0F; // Set DLAB=0 to lock MULVAL and DIVADDVAL
}

void uart1_tx_char(char ch)// Writing char	
{
	while ( !(U1LSR & THRE ) ); // wait till the THR becomes empty
  U1THR = ch;	//write to the Tx FIFO
}

void uart1_tx_string(char *str_ptr)
{
	while(*str_ptr)
	uart1_tx_char(*str_ptr++);
}

char uart1_rx_char(void)	//Reading char
{
	while( !(U1LSR & RDR ) ); // wait till any data arrives into Rx FIFO
	
	if(ECHO) uart1_tx_char(U1RBR);						// if echo is enabled
	
		return U1RBR;			//return received char
}

void uart1_rx_string()
{
	int i;
	char buffer[10],ch ;
	for(i=0;U1RBR!=ENTER;i++)
		{
	while( !(U1LSR & RDR ) ); // wait till any data arrives into Rx FIFO
	buffer[i]=U1RBR;
		}
		if(ECHO) uart1_tx_string(buffer);				// if echo is enabled
}
#endif