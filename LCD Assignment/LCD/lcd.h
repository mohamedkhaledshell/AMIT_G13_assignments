/*
 * lcd.h
 *
 * Created: 30-May-20 1:27:01 PM
 *  Author: Mohamed Khaled Shell
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_PORT PORTA
#define LCD_CTRL PORTB
#define LCD_Dir DDRA
#define LCD_CTRL_Dir DDRB
#define RS 1
#define RW 2
#define E	3

void LCD_init();
void LCD_command(char cmd);
void LCD_char(char data);
void LCD_string(char* str);




#endif /* LCD_H_ */