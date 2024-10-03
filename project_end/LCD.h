/*
 * LCD.h
 *
 *  Created on: 6 Sep 2022
 *      Author: p&p
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_commend(char command);
void LCD_data(char data);
void LCD_Init(void);
void LCD_string(char * ptr);
void LCD_GOTOXY(char pos_x,char pos_y);
void LCD_specialchar(char *pattern,char pattern_number,char pos_x,char pos_y);


#endif /* LCD_H_ */
