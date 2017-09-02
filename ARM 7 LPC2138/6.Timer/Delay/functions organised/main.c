/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 24/07/17
 * Note(s): initialize Timer to produce 20ms delay
						XTAL = 12.0Mhz
						PCLK = 60MHz
 *----------------------------------------------------------------------------*/
 #include <LPC213X.H>
#include "PLL.h"
#include "delay.h"

int main()
{
IODIR0=0xffffffff;
init_PLL();			//PCKL = 60MHz Required
enable_delays();
while(1)
{
IOSET0=0xffffffff;
delay_ms(50);
IOCLR0=0xffffffff;
delay_ms(50);
}
}
