/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 23/07/17
 * Note(s): initialize PLL for system clock to work at 60MHz
			XTAL = 12.0MHz
			CPU = 60MHz
			PCLK = 60MHz
 *----------------------------------------------------------------------------*/
 
#include <LPC213X.H>
#include "PLL.h"

int main()
{
init_PLL();
}
