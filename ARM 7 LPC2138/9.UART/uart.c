/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 9 July, 2017
 * Note(s): Cclk=12MHz
						Pclk=60MHz
						Baud rate = 9600
 *----------------------------------------------------------------------------*/

#include<lpc213x.h>
#include"PLL.h"

#define THRE (1<<5) // Transmit Holding Register Empty
#define RDR (1<<0) // Receiver Data Ready
#define MULVAL 1
#define DIVADDVAL 0
#define NEW_LINE 0xA // ASCII code for new line
#define ENTER 0xD // ASCII code for Enter 

int main()
{
int rxdata;
init_PLL();
	
  PINSEL0 = 0x5;  // pin collect block to function as UART
  U0LCR	= 3 | (1<<7) ; // 8 bits, no Parity, 1 Stop bit | set DLAB = 1  
  U0DLM = 1;
	U0DLL	= 135;	// see UART calculations
  U0FDR = (MULVAL<<4) | DIVADDVAL;  
  U0LCR &= 0x0F; // Set DLAB=0 to lock MULVAL and DIVADDVAL
	// Baud is set to 9600

// Writing char	
	while ( !(U0LSR & THRE ) ); // wait till the THR becomes empty
     U0THR = 'A';	//write to the Tx FIFO

	while(1)
{
	//Reading char
	while( !(U0LSR & RDR ) ); // wait till any data arrives into Rx FIFO
	rxdata=U0RBR;			//store received char to rxdata variable
	
	//echoing received char
	while ( !(U0LSR & THRE ) ); // wait till the THR becomes empty
     U0THR = rxdata;	//write to the Tx FIFO
}
}