/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 04/07/17
 * Note(s): LCD 4 bit interfacing
 *----------------------------------------------------------------------------*/

#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"
#include"lcd4.h"

int main()
{
init_PLL();
enable_delays();
init_lcd();
	while(1)
	{
		lcd_string(1,1,"Line 1");
		lcd_string(2,1,"Line 2");
		lcd_string(3,1,"Line 3");
		lcd_string(4,1,"Line 4");
	}
}

