/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 01/07/17
 * Note(s): initialize PLL for system clock to work at 60Mhz for XTAL = 12.0MHz
						XTAL = 12.0Mhz
						PCLK = 60MHz
 *----------------------------------------------------------------------------*/
 
#ifndef __seven_seg_h
#define __seven_seg_h

#include<lpc213x.h>

#define bit(x) (1<<x)		//for bitwise operations

// Seven segment driver connections

#define B0 bit(16)
#define B1 bit(17)
#define B2 bit(18)
#define B3 bit(19)

void init_seven_seg()
{
  IODIR0 |= (B0|B1|B2|B3); // set lines as output
}

void seven_seg(unsigned int a)
{
	 if	(a & 1) IOSET0 |= B0;
	 else IOCLR0 |= B0;
	 if	(a & 2) IOSET0 |= B1;
	 else IOCLR0 |= B1;
	 if	(a & 4) IOSET0 |= B2;
	 else IOCLR0 |= B2;
	 if	(a & 8) IOSET0 |= B3;
	 else IOCLR0 |= B3;
}
#endif