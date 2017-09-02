/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date Created : 11 July, 2017
 * Note(s):
 *----------------------------------------------------------------------------*/
 
#include <lpc213x.h>
#include"PLL.h"
#include"delay.h"

#define bit(x) (1<<x)		//for bitwise operations
#define p1 bit(16)
#define p2 bit(17)
#define p3 bit(18)
#define p4 bit(19)

void clockwise();
void anticlockwise();
void stop();

int main(void)
{
init_PLL();
enable_delays();
IODIR0 |= p1;			//P0.16 as output
IODIR0 |= p2;			//P0.17 as output
IODIR0 |= p3;		//P0.18 as output
IODIR0 |= p4;			//P0.19 as output

IOCLR0 |= 0xffffffff;

	while(1)
{
	clockwise(10);
	//	stop(1);
 //anticlockwise(2);
	//	stop(1);	
}
}

void clockwise(unsigned int c) //Rotates Motor Clockwise
{
	int i;
   for(i=0;i<c;i++)
	 {
	 IOSET0 |= p1; //0001
   delay_ms(200);
	 IOCLR0 |= p1;
   IOSET0 |= p3; //0100
   delay_ms(200);
	 IOCLR0 |= p3;
   IOSET0 |= p2; //0010
   delay_ms(200);
	 IOCLR0 |= p2;
   IOSET0 |= p4; //1000
   delay_ms(200);
	 }
}

//void anticlockwise(unsigned int a)
//{
//int i;
//	for(i=0;i<a;i++)
//	 {
//   P2=0x08; //1000
//   delay_ms(200);
//   P2=0x02; //0010
//   delay_ms(200);
//   P2=0x04; //0100
//   delay_ms(200);
//   P2=0x01; //0001
//   delay_ms(200);
//	 }
//}

//void stop(unsigned int s)
//{
//int i;
//	for(i=0;i<s;i++)
//{
// IOCLR0 |= 0xffffffff;
// delay_ms(1000);
//}
//}
