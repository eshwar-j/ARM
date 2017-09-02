/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 9 July, 2017
 * Note(s): Cclk=12MHz
						Pclk=60MHz
						Baud rate = 9600
 *----------------------------------------------------------------------------*/

#include<lpc213x.h>
#include"PLL.h"
#include"uart0.h"

int main()
{
init_PLL();
init_uart0();
uart0_tx_string("type your string and press enter\n\r");
uart0_rx_string();
while(1);
}