/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 03/07/17
 * Note(s): seven seg 3 digit multiplexing
 *----------------------------------------------------------------------------*/
#ifndef __seven_seg_multiplexed_CC_h
#define __seven_seg_multiplexed_CC_h

#include"lpc213x.h"
#include"delay.h"

#define bit(x) (1<<x)		//for bitwise operations

// seven segment connections

#define B0 bit(16)
#define B1 bit(17)
#define B2 bit(18)
#define B3 bit(19)

#define units_module bit(20)
#define tens_module bit(21)
#define hundreds_module bit(22)

void init_seven_seg()
{
  IODIR0 |= (B0|B1|B2|B3|units_module|tens_module|hundreds_module); // set lines as output

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

int ones=0,tens=0,hundreds=0;
extern int count=0;

void current_count()
{
ones=count%10;
tens=(count/10)%10;
hundreds=(count/100);
	
seven_seg(ones);
IOCLR0 |= units_module;
delay_ms(20);
IOSET0 |= units_module;

seven_seg(tens);
IOCLR0 |= tens_module;
delay_ms(20);
IOSET0 |= tens_module;

seven_seg(hundreds);
IOCLR0 |= hundreds_module;
delay_ms(20);
IOSET0 |= hundreds_module;	
}

void count_up()
{
count=count+1;
current_count();	
}

void count_down()
{
count=count-1;
current_count();	
}
#endif