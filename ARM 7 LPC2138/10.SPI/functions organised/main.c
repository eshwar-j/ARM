#include<lpc213x.h>
#include"PLL.h"
#include"delay.h"

unsigned char spi_rec;

void spi_ini();
void spi_tr1(unsigned int x);
char spi_re();
void spi_tr(unsigned char cmd,unsigned char data);
void spi_str(unsigned char *str);

int seg[10]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f };
int module_on[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};

void delay_ms(unsigned int x);

int main()
   {
			int i,a,b,c,d,e,f,g,h;
			a=b=c=d=e=f=g=h=0;
			PINSEL0=0X00000000;
			IO0DIR=0XFFFFFFFF;
			init_PLL();
		 enable_delays();
			spi_ini();
			spi_tr(0x0a,0xf);
			spi_tr(0x0b,0xf);   
			for(i=0;i<9;i++)
	      {
	          spi_tr(module_on[i],seg[0]);
	          delay_ms(100);
	      }
	   spi_tr(0x0c,0x01);
	   while(1)
	     {
		       spi_tr(module_on[7],seg[a]);
		       spi_tr(module_on[6],seg[b]);
		       spi_tr(module_on[5],seg[c]);
		       spi_tr(module_on[4],seg[d]);
		       spi_tr(module_on[3],seg[e]);
		       spi_tr(module_on[2],seg[f]);
		       spi_tr(module_on[1],seg[g]);
		       spi_tr(module_on[0],seg[h]);
		       a++;

           if(a==10)
		        {
		           a=0;
			         b++;
		        }
		       if(b==10)
		        {
		           a=b=0;
			         c++;
		        }
		      if(c==10)
		        {
		           a=b=c=0;
			         d++;
		        }
		      if(d==10)
		        {
		           a=b=c=d=0;
			         e++;
		        }
		      if(e==10)
		        {
		            a=b=c=d=e=0;
			          f++;
		        }
		      if(f==10)
		        {
		             a=b=c=d=e=f=0;
                 g++;
		        }
		      if(g==10)
		        {
		             a=b=c=d=e=f=g=0;
			           h++;
		        }
		      if(h==10)
		        {
		            a=b=c=d=e=f=g=h=0;
		        }
		     delay_ms(3000);	 
	    }
  }

void spi_ini()
  {
		 PINSEL0 |=0x1500;          /* P0.4, P0.5, P0.6, P0.7 are set as SCK, MISO, MOSI and GPIO */
		 IODIR0 |= 0X80; 				  /* SSEL is output */
		 IOSET0 |=0X80; 				  /* set SSEL to high */
		 S0SPCCR=8;						      /* SPI clock prescale register minimum value is 8. */
		 S0SPCR=0x30;					    /* Device select as master, Set data to 8-bit, CPOL = 0, CPHA = 0*/ 
  }

void spi_tr1(unsigned int x)
  {
     S0SPDR =x;
     while ( !(S0SPSR & 0x80) );	/* Wait until the SPIF bit is set to indicate trabsfer complete */
  }

char spi_re()
  {
	    while ( !(S0SPSR & 0x80) );	/* Wait until the SPIF bit is set to indicate trabsfer complete */
      spi_rec= S0SPDR;
      return spi_rec;
  }

void spi_str(unsigned char *str)
  {
     while(*str!='\0')
      {
        spi_tr1(*str);
        str++;
      }
  }
	
void spi_tr(unsigned char cmd,unsigned char data)
	{
		IO0CLR=(1<<7);  //enable transmission
		spi_tr1(cmd);
		spi_tr1(data);
		IO0SET=(1<<7);   // disable transmission

	}