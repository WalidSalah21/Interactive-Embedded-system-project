/*
 * keybad.c
 *
 *  Created on: 10 Sep 2022
 *      Author: p&p
 */
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "LCD.h"
#include "keybad.h"



char keyfind()
{
	unsigned char colloc, rowloc;
	unsigned char keypad[4][4] = {	{'7','8','9','/'},
					{'4','5','6','*'},
					{'1','2','3','-'},
					{' ','0','=','+'}};
	DDRA =0xF0;           /* set port direction as input-output */
    PORTA=0xFF;

	while(1)
	{
		DDRA =0xF0;           /* set port direction as input-output */
	    PORTA=0xFF;

	    do
	    {
		KEY_PRT &= 0x0F;      /* mask PORT for column read only */
		asm("NOP");
		colloc = (PINA & 0x0F); /* read status of column */
	    }while(colloc != 0x0F);

	    do
	    {
		do
		{
	            _delay_ms(20);             /* 20ms key debounce time */
		    colloc = (KEY_PIN & 0x0F); /* read status of column */
		}while(colloc == 0x0F);        /* check for any key press */

		_delay_ms (40);	            /* 20 ms key debounce time */
		colloc = (KEY_PIN & 0x0F);
	    }while(colloc == 0x0F);

	   /* now check for rows */
	    KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
	    asm("NOP");
	    colloc = (KEY_PIN & 0x0F);
	    if(colloc != 0x0F)
            {
		rowloc = 0;
		break;
	    }

	    KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
	    asm("NOP");
	    colloc = (KEY_PIN & 0x0F);
	    if(colloc != 0x0F)
	    {
		rowloc = 1;
		break;
	    }

	    KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
	    asm("NOP");
            colloc = (KEY_PIN & 0x0F);
	    if(colloc != 0x0F)
	    {
		rowloc = 2;
		break;
	    }

	    KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
	    asm("NOP");
	    colloc = (KEY_PIN & 0x0F);
	    if(colloc != 0x0F)
	    {
		rowloc = 3;
		break;
	    }
	}

	if(colloc == 0x0E)
	   return(keypad[rowloc][0]);
	else if(colloc == 0x0D)
	   return(keypad[rowloc][1]);
	else if(colloc == 0x0B)
	   return(keypad[rowloc][2]);
	else
	   return(keypad[rowloc][3]);
}
