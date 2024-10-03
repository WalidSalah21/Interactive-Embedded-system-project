/*
 * LCD.c
 *
 *  Created on: 6 Sep 2022
 *      Author: p&p
 */
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "LCD.h"



void LCD_commend(char command)
{
	CLR_BIT(PORTC,0) ;   /*CLEAR RS BIN    A0*/
	CLR_BIT(PORTC,1) ;   /*CLEAR R/W BIN    A1*/

	PORTB = command;     /*send commend to LCD m.c on data pins*/
	/*ENABLE PULSE*/
	SET_BIT(PORTC,2) ;
	_delay_ms(2);  /*delay 2 ms*/
	CLR_BIT(PORTC,2);

}
void LCD_data(char data)
{
	SET_BIT(PORTC,0) ;   /*CLEAR RS BIN    A0*/
	CLR_BIT(PORTC,1) ;   /*CLEAR RS BIN    A1*/

	PORTB = data;       /*send commend to LCD m.c on data pins*/
	/*ENABLE PULSE*/
	SET_BIT(PORTC,2) ;
	_delay_ms(2);  /*delay 2 ms*/
	CLR_BIT(PORTC,2);


}
void LCD_Init(void)
{
    /*wait for more than 30 ms second*/
	_delay_ms(40);

    /*2 lines ,5*8size */
 	LCD_commend(0b00111000);

 	/*display enable ,cursor disable */
 	LCD_commend(0b00001100);

 	/*display clear */
 	LCD_commend(1);



}

void LCD_string(char * ptr)
{
	char i=0;
	while(ptr[i]!='\0')
		{
		 LCD_data(ptr[i]);
     i++;
		}


}

void LCD_GOTOXY(char pos_x,char pos_y)
{
	/*first line*/
	char Adress;
	if(pos_x==0)
		{
	      Adress=pos_y;
		}
		/*second line*/
	else if(pos_x==1)
		{

			Adress=pos_y+0x40;


        }
	LCD_commend(Adress+128);   /*128 TO MAKE SURE MSB ALWEYS =1*/
}

void LCD_specialchar(char *pattern,char pattern_number,char pos_x,char pos_y)
{
	char Address=0,counter=0;
	Address=pattern_number*8;
	 LCD_commend(64+Address);

	 for(counter=0;counter<8;counter++)
	 {
		 LCD_data(pattern[counter]);

	 }
	 LCD_GOTOXY(pos_x,pos_y);
	 LCD_data(pattern_number);

}


