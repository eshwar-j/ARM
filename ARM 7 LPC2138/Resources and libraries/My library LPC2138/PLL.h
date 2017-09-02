/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 22/07/17 to 23/07/17
 * Note(s): initialize PLL for system clock to work at 60Mhz for XTAL = 12.0MHz
						XTAL = 12.0Mhz
						PCLK = 60MHz
 *----------------------------------------------------------------------------*/

#include <lpc213x.h>
#define PLOCK 0x00000400

#ifndef __PLL_H
#define __PLL_H
void init_PLL(void)
{
   PLLCON = 0x01; //PLL enabled but not connected 
   PLLCFG = 0x24; //M=5, P=2

   PLLFEED = 0xAA;
   PLLFEED = 0x55;

   while(!(PLLSTAT & PLOCK));
  
   PLLCON = 0x03; // now enable(again) and connect
	
   PLLFEED = 0xAA;
   PLLFEED = 0x55;

   VPBDIV = 0x01; // PCLK is same as CCLK i.e 60MHz 
}
#endif
