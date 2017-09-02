/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 20/07/17
 * Note(s): switch P1.16
						relay P0.31
 *----------------------------------------------------------------------------*/

#include <lpc213x.h>
#define bit(x) (1<<x)		//for bitwise operations
#define sw bit(16)
#define relay bit(31)

int main(void)
{
     IODIR1 &= ~sw;		//P1.23 as input SW, other pins not affected
     IODIR0 |= relay;			//P0.1 as output relay, other pins not affected	

     while(1)
     {
	 if(!(IOPIN1 & sw))		//check sw pin at P1.23
		 IOSET0 |= relay;	//set P0.1 high
	 else
		 IOCLR0 |= relay;		//set P0.1 low
     }
}