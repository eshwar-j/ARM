/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 22/07/17 to 23/07/17
 * Note(s): initialize PLL for system clock to work at 60MHz
			XTAL = 12.0MHz
			CPU = 60MHz
			PCLK = 60MHz
 *----------------------------------------------------------------------------*/

#include <lpc213x.h>
#define PLOCK 0x00000400

int main(void)
{
   PLLCON = 0x01; // PPLE=1 & PPLC=0, only PLL enabled but not connected 
   PLLCFG = 0x24; // set the multiplier to 5 (i.e actually 4)  12x5 = 60 MHz (M - 1 = 4)!!!
                  // Set P=2 since we want FCCO in range!!!
                  // So , Assign PSEL =01 in PLLCFG as per the table.

   PLLFEED = 0xAA; // Unlock the PLL registers by sending the sequence(0xAA-0x55)
   PLLFEED = 0x55;

   while(!(PLLSTAT & PLOCK)); // check whether PLL has locked on to the desired freq by reading the lock bit in the PPLSTAT register
  
   PLLCON = 0x03; // now enable(again) and connect
	
   PLLFEED = 0xAA; // lock the PLL registers after setting the required PLL
   PLLFEED = 0x55;
					//SysClock is now ticking @ 60MHz!

   VPBDIV = 0x01; // PCLK is same as CCLK i.e 60MHz 
}