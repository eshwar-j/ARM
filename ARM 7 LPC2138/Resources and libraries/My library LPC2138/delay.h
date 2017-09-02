/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 24/07/17
 * Note(s): initialize Timer to produce required delay in sec & ms
						XTAL = 12.0Mhz
						PCLK = 60MHz
 *----------------------------------------------------------------------------*/

#include <lpc213x.h>
#define PCLK 60000000
#define PRESCALER ((PCLK*0.001)-1)

#ifndef __timer_H
#define __timer_H

void enable_delays(void)
{
T0CTCR = 0x00;	//Select timer mode
T0PR = PRESCALER;
T0TCR = 0x02; //Reset Timer
}

void delay_ms(unsigned int ms)
{
T0TCR = 0x02; //Stop Timer
T0TCR = 0x01; //Run timer

while(T0TC < ms);

T0TCR = T0TC = 0x00; //Stop timer
T0PC = 0x00;				//reset PC
}

void delay_sec(unsigned int sec)
{
delay_ms(sec*1000);
}
#endif
