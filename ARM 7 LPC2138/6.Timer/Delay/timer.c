/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 23/07/17 to 24/07/17
 * Note(s): initialize Timer to produce 20ms delay
						XTAL = 12.0Mhz
						PCLK = 60MHz
 *----------------------------------------------------------------------------*/

#include <lpc213x.h>
#include "PLL.h"

int main()
{
unsigned int milliseconds=20;	//provide decimal value delay in ms, auto converted to hex 
	
init_PLL();			//PCKL = 60MHz Required

T0CTCR = 0x00;		//Set Timer 0 into Timer Mode
T0TCR = 0x02;		//Reset Timer
	
T0PR = 59999;		//(60000000 x 0.001ms) – 1 = 59999
								//Count begins from zero hence subtract 1
								//Increment T0TC at every 60000 clock cycles
								//60000 clock cycles @60Mhz = 1 mS

T0TCR = 0x01;		//Run timer
while(T0TC < milliseconds);	//wait until TC reaches the desired delay
T0TCR = 0x00;		//Stop timer
	
while(1);
}
