/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 11 July, 2017
 * Note(s): Servo Motor control
 error with controls
 *----------------------------------------------------------------------------*/
 
#include <lpc213x.h>
#include"PLL.h"
#include"delay.h"

#define bit(x) (1<<x)		//for bitwise operations
#define servo_pin bit(17)

void zero_deg();
void ninety_deg();
void oneeighty_deg();

int main(void)
{
init_PLL();
enable_delays();
IODIR0 |= servo_pin;			//P0.17 as output


	while(1)
{
zero_deg();
delay_sec(1);
ninety_deg();
delay_sec(1);
oneeighty_deg();
delay_sec(1);
}
}

void zero_deg() //Rotates Motor 0 deg
{
	IOSET0 |= servo_pin;
	delay_ms(1);
	IOCLR0 |= servo_pin;
}

void ninety_deg() //Rotates Motor Anticlockwise
{
	IOSET0 |= servo_pin;
	delay_ms(1.5);
	IOCLR0 |= servo_pin;
}

void oneeighty_deg() //Stops motor
{
 IOSET0 |= servo_pin;
 delay_ms(2);
 IOCLR0 |= servo_pin;
}