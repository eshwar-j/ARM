/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 20/07/17
 * Note(s): LED port P0
 *----------------------------------------------------------------------------*/
 
 #include<lpc213x.h>

void delay()
   {
         int i,j;
         for(i=0;i<100;i++)
         for(j=0;j<1000;j++);
   }
	 
int main()
   {
   //PINSEL0=0x00000000; selecting port0 pin0~15 in GPIO mode. On reset, default mode of pin connect block is GPIO
		 
        IODIR0=0xffffffff; // declare port0 pins as output
        while(1)
          {
                IOPIN0=0xffffffff;  // set port0 pins or IOSET0 will also work
                delay();
                IOPIN0=0x00;  // clear the port0 pins or IOCLR0=0xffffffff will also work
                delay();
          }
   }

