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
		lcd_string(1,1,"LCD 4 bit");
		lcd_string(2,1,"on ARM 7");
	}
}

