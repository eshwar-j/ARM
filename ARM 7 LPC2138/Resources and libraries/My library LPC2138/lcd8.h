/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 04/07/17
 * Note(s): LCD 8 bit interfacing
 
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

#ifndef __lcd8_h
#define __lcd8_h

#include"delay.h"

#define bit(x) (1<<x)		//for bitwise operations

// LCD 8 bit

#define D0 bit(0)
#define D1 bit(1)
#define D2 bit(2)
#define D3 bit(3)
#define D4 bit(4)
#define D5 bit(5)
#define D6 bit(6)
#define D7 bit(7)

#define rs bit(8)
#define en bit(9)

void lcd_port(char a)
{
	 if	(a & 1)	  IOSET0 |= D0;
	 else IOCLR0 |= D0;
	 if	(a & 2)   IOSET0 |= D1;
	 else IOCLR0 |= D1;
	 if	(a & 4) 	IOSET0 |= D2;
	 else IOCLR0 |= D2;
	 if	(a & 8) 	IOSET0 |= D3;
	 else IOCLR0 |= D3;
	 if	(a & 16) 	IOSET0 |= D4;
	 else IOCLR0 |= D4;
	 if	(a & 32) 	IOSET0 |= D5;
	 else IOCLR0 |= D5;
	 if	(a & 64) 	IOSET0 |= D6;
	 else IOCLR0 |= D6;
	 if	(a & 128) IOSET0 |= D7;
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
	IOSET0 |=	rs;             // => RS = 1
  lcd_port(a);     			  	//Data transfer
	IOSET0 |= en;             // => E = 1
	delay_ms(1);
	IOCLR0 |= en;             // => E = 0
}

void setcursor(char row, char column)
{
	if(row == 1)
	  lcd_cmd(0x80 + (column-1));		//line 1 address 80...8F
	if(row == 2)
		lcd_cmd(0xC0 + (column-1));		//line 2 address C0...CF
	if(row == 3)
	  lcd_cmd(0x90 + (column-1));		//line 3 address 90...9F
	if(row == 4)
		lcd_cmd(0xD0 + (column-1));		//line 4 address D0...DF
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
	IODIR0 |= (D0|D1|D2|D3|D4|D5|D6|D7|rs|en);
	
	///////////// Reset process from datasheet /////////	
	lcd_cmd(0x30); 
	 delay_ms(10);
	lcd_cmd(0x30);
	 delay_ms(10);
	lcd_cmd(0x30);
	 delay_ms(2);
  /////////////////////////////////////////////////////	
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
}

void lcd_clear()
{
	lcd_cmd(0x01);
}

void lcd_shift_left()
{
	lcd_cmd(0x18);
}

void lcd_shift_right()
{
	lcd_cmd(0x1c);
}
#endif