/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 04/07/17
 * Note(s): LCD 8 bit interfacing
 *----------------------------------------------------------------------------*/

#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"
#include"lcd8.h"

int main()
{
init_PLL();
enable_delays();
init_lcd();
	while(1)
	{
		lcd_string(1,1,"lcd 8 bit");
		lcd_string(2,3,"on ARM 7");
	}
}

