/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Created on 14 June, 2017
 * Note(s):
 *----------------------------------------------------------------------------*/
 
#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"
#include"lcd4.h"
#include"keypad.h"

char c;
int main(void)
{
init_PLL();
enable_delays();
init_keypad();
init_lcd();
	lcd_string(1,1,"Keys pressed ");
    while(1)
     {
			 setcursor(1,14);
       c=read_keypad();
       lcd_raw(c);
      }
}