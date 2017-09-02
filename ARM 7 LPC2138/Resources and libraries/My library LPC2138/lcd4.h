/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 04/07/17
 * Note(s): LCD 4 bit interfacing
 
 LCD functions
 init_lcd();											initialize LCD
 lcd_clear(); 										clears LCD
 setcursor(row,col); 	  					specify row and colomn, Range(1,1) to (4,16)
 lcd_raw('c');										writes character at current cursor position, auto increment cursor
 lcd_raw(data);										writes ascii data to lcd, auto increments cursor
 lcd_string(row,col,"string");		write word or sentence to given row and column
 lcd_shift_right();		 	 				  shift LCD content right
 lcd_shift_left(); 		 	 				  shift LCD content left
 
 RW is assumed grounded
 *----------------------------------------------------------------------------*/

#ifndef __lcd4_h
#define __lcd4_h

#include"delay.h"

#define bit(x) (1<<x)		//for bitwise operations

// LCD 4 bit

#define D4 bit(8)
#define D5 bit(9)
#define D6 bit(10)
#define D7 bit(11)

#define rs bit(12)
#define en bit(13)

void lcd_port(char a)
{
	 if	(a & 1) IOSET0 |= D4;
	 else IOCLR0 |= D4;
	 if	(a & 2) IOSET0 |= D5;
	 else IOCLR0 |= D5;
	 if	(a & 4) IOSET0 |= D6;
	 else IOCLR0 |= D6;
	 if	(a & 8) IOSET0 |= D7;
	 else IOCLR0 |= D7;
}

void lcd_cmd(char a)
{ 
	IOCLR0 |=	rs;             // => RS = 0
	lcd_port(a);
	IOSET0 |= en;             // => E = 1
  delay_ms(1);
	IOCLR0 |= en;             // => E = 0
}

void lcd_raw(char a)
{	
	 IOSET0 |= rs;             // => RS = 1
   lcd_port((a&0xF0)>>4);     // transfer higher nibble
	 IOSET0 |= en;
	 delay_ms(1);
	 IOCLR0 |= en;
	 lcd_port(a&0x0F);     			// transfer lower nibble
	 IOSET0 |= en;
	 delay_ms(1);
	 IOCLR0 |= en;
}

void setcursor(char row, char column)
{
	if(row == 1)  			 //line 1 address 0x80....0x8F
	{
		lcd_cmd(0x8);											//send 0x8
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
	if(row == 2) 	 			//line 2 address 0xC0....0xCF
	{
		lcd_cmd(0xC);											//send 0xC
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
	if(row == 3)				// line 3 address 90....9F, valid only for 16x4 LCD
	{
		lcd_cmd(0x9);											//send 0x9
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
	if(row == 4)				//line 3 address 0xD0....0xDF, valid only for 16x4 LCD
	{
		lcd_cmd(0xD);											//send 0xD
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
}

void lcd_string(char row, char column, char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(i==0) setcursor(row,column);
			lcd_raw(str[i]);
	}
}

void init_lcd()
{
	IODIR0 |= (D4|D5|D6|D7|rs|en);
	
	///////////// Reset process from datasheet /////////
  lcd_cmd(0x03);
	delay_ms(10);
  lcd_cmd(0x03);
	delay_ms(2);
  lcd_cmd(0x03);
  /////////////////////////////////////////////////////
  lcd_cmd(0x02);    
	lcd_cmd(0x02);
  lcd_cmd(0x08); 	
	lcd_cmd(0x00); 
	lcd_cmd(0x0C);     
  lcd_cmd(0x00);    
  lcd_cmd(0x06); 
}

void lcd_clear()
{
	lcd_cmd(0x0);
	lcd_cmd(0x1);
}

void lcd_shift_left()
{
	lcd_cmd(0x01);
	lcd_cmd(0x08);
}

void lcd_shift_right()
{
	lcd_cmd(0x01);
	lcd_cmd(0x0C);
}
#endif