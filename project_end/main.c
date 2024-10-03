/*
 * main.c
 *
 *  Created on: 10 Sep 2022
 *      Author: p&p
 */

#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "LCD.h"

void main()
{
	char gun[5]={127,127,104,120,96};
	char man[5]={14,14,4,127,4};
	char bullet[5]={28,28,0,0,0};
	char clear[5]={0,0,0,0,0};
	char i;

	DDRB=0Xff;  /*set port B */
	DDRC=0x0f;  /*set first 3 bits in port A */
	LCD_Init();
	int inp_number=0xff;





	while(1)
	{
		LCD_commend(1);
		LCD_string(" enter an number");
		_delay_ms(1000);
		LCD_commend(1);
		LCD_specialchar(gun,5,0,0);
		LCD_specialchar(man,1,0,15);



		//_delay_ms(5000);
		inp_number= keyfind();
		while(inp_number==0xff)
		{
			inp_number= keyfind();

			//keypad= keybad_fun();
			//if(keypad=='1')
			//{
			//	break;
			//}

		}
		for (i=1;i<=15;i++)
		{
			LCD_specialchar(gun,5,0,0);
			LCD_specialchar( bullet,2,0,i);
			_delay_ms(500);
			LCD_commend(1);
			LCD_specialchar(gun,5,0,0);
			LCD_specialchar(man,1,0,15);


		}
		LCD_commend(1);
		LCD_GOTOXY(1,0);
		LCD_string("man is dead");
		_delay_ms(3000);
	}
}


