/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 11 July, 2017
 * Note(s): DC Motor control

	pin 1				pin2				action
	
		0						0					stop
		0						1					clockwise
		1						0					anticlockwise
		1						1					stop
 *----------------------------------------------------------------------------*/
 
#include <lpc213x.h>
#include"PLL.h"
#include"delay.h"

#define bit(x) (1<<x)		//for bitwise operations
#define p1 bit(21)
#define p2 bit(22)

void clockwise();
void anticlockwise();
void stop();

int main(void)
{
init_PLL();
enable_delays();
IODIR0 |= p1;			//P0.21 as output
IODIR0 |= p2;			//P0.22 as output

	while(1)
{
clockwise();
delay_sec(2);
stop();
delay_sec(2);
anticlockwise();
delay_sec(2);
stop();
delay_sec(2);
}
}

void clockwise() //Rotates Motor Clockwise
{
	 IOCLR0 |= p1;
	 IOSET0 |= p2;
}

void anticlockwise() //Rotates Motor Anticlockwise
{
	 IOSET0 |= p1;
	 IOCLR0 |= p2;
}

void stop() //Stops motor
{
	 IOSET0 |= p1;
	 IOSET0 |= p2;
}