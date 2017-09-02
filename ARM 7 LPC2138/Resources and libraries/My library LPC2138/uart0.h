/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 9 July, 2017
 * Note(s): Cclk=12MHz
						Pclk=60MHz
						Baud rate = 9600
 *----------------------------------------------------------------------------*/

#include<lpc213x.h>
#include"PLL.h"

#ifndef __uart0_h
#define __uart0_h

#define THRE (1<<5) // Transmit Holding Register Empty
#define RDR (1<<0) // Receiver Data Ready
#define MULVAL 1
#define DIVADDVAL 0
#define NEW_LINE 0xA // ASCII code for new line
#define ENTER 0xD // ASCII code for Enter
#define ECHO 1		// echo received strings and chars
void init_uart0()
{
	PINSEL0 = 0x5;  // pin collect block to function as UART
  U0LCR	= 3 | (1<<7) ; // 8 bits, no Parity, 1 Stop bit | set DLAB = 1  
  U0DLM = 1;
	U0DLL	= 135;	// value for 9600. see UART calculations
  U0FDR = (MULVAL<<4) | DIVADDVAL;  
  U0LCR &= 0x0F; // Set DLAB=0 to lock MULVAL and DIVADDVAL
}

void uart0_tx_char(char ch)// Writing char	
{
	while ( !(U0LSR & THRE ) ); // wait till the THR becomes empty
  U0THR = ch;	//write to the Tx FIFO
}

void uart0_tx_string(char *str_ptr)
{
	while(*str_ptr)
	uart0_tx_char(*str_ptr++);
}

char uart0_rx_char(void)	//Reading char
{
	while( !(U0LSR & RDR ) ); // wait till any data arrives into Rx FIFO
	
	if(ECHO) uart0_tx_char(U0RBR);						// if echo is enabled
	
		return U0RBR;			//return received char
}

void uart0_rx_string()
{
	int i;
	char buffer[10],ch ;
	for(i=0;U0RBR!=ENTER;i++)
		{
	while( !(U0LSR & RDR ) ); // wait till any data arrives into Rx FIFO
	buffer[i]=U0RBR;
		}
		if(ECHO) uart0_tx_string(buffer);				// if echo is enabled
}
#endif