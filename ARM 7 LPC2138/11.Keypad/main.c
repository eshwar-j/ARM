/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Created on 14 June, 2017
 * Note(s):
 *----------------------------------------------------------------------------*/
 
#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"
#include"lcd8.h"

#define bit(x) (1<<x)		//for bitwise operations

#define R1 bit(16)
#define R2 bit(17)
#define R3 bit(18)
#define R4 bit(19)
#define C1 bit(20)
#define C2 bit(21)
#define C3 bit(22)
#define C4 bit(23)

char c;
char keypad();
int main(void)
{
PINSEL0=PINSEL2=0;
IODIR1 |= (R1|R2|R3|R4);		//for toggle rows, set as output
IODIR1 &= (~C1&~C2&~C3&~C4);		//for scan columns, set as input
IOCLR0 |=(R1|R2|R3|R4|C1|C2|C3|C4);
		init_lcd();
    while(1)
     {
       c=keypad();
       lcd_raw(c);
      }
}
char keypad(void)
 {  
   while(1)
   {
IOCLR1|=R1;
IOSET1|=(R2|R3|R4);
if(!(IOPIN1&C1)){while(!(IOPIN1&C1));return '/';}
if(!(IOPIN1&C2)){while(!(IOPIN1&C2));return '9';}
if(!(IOPIN1&C3)){while(!(IOPIN1&C3));return '8';}
if(!(IOPIN1&C4)){while(!(IOPIN1&C4));return '7';}

IOCLR1|=R2;
IOSET1|=(R1|R3|R4);
if(!(IOPIN1&C1)){while(!(IOPIN1&C1));return '*';}
if(!(IOPIN1&C2)){while(!(IOPIN1&C2));return '6';}
if(!(IOPIN1&C3)){while(!(IOPIN1&C3));return '5';}
if(!(IOPIN1&C4)){while(!(IOPIN1&C4));return '4';}

IOCLR1|=R3;
IOSET1|=(R1|R2|R4);
if(!(IOPIN1&C1)){while(!(IOPIN1&C1));return '-';}
if(!(IOPIN1&C2)){while(!(IOPIN1&C2));return '3';}
if(!(IOPIN1&C3)){while(!(IOPIN1&C3));return '2';}
if(!(IOPIN1&C4)){while(!(IOPIN1&C4));return '1';}

IOCLR1|=R4;
IOSET1|=(R1|R2|R3);
if(!(IOPIN1&C1)){while(!(IOPIN1&C1));return '+';}
if(!(IOPIN1&C2)){while(!(IOPIN1&C2));return '=';}
if(!(IOPIN1&C3)){while(!(IOPIN1&C3));return '0';}
if(!(IOPIN1&C4)){while(!(IOPIN1&C4));return 'c';}
			 
   }
}