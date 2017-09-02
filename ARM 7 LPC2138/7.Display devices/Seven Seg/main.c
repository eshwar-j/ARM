/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 03/07/17
 * Note(s): seven segment multi purpose
 *----------------------------------------------------------------------------*/
 
#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"
#include"seven_seg.h"

int main()
{
	init_PLL();
	enable_delays();
	init_seven_seg();
	seven_seg(5);
	delay_ms(100);
	seven_seg(7);
	while(1);
}