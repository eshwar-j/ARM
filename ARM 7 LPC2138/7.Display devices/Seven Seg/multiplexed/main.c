/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 03/07/17
 * Note(s): seven segment 3 digit multiplexed
 *----------------------------------------------------------------------------*/
 
#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"
#include"seven_seg_multiplexed_CC.h"

int main()
{
init_PLL();
init_seven_seg();
enable_delays();
count_up();
count_up();
count_up();
count_down();
	while(1)
		{
		current_count();
		}
}