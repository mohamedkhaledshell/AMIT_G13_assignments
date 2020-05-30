/*
 * lcd.c
 *
 * Created: 30-May-20 1:26:47 PM
 *  Author: Mohamed Khaled Shell
 */ 
#include "lcd.h"


void LCD_init()
{
	//direction of data pins
	LCD_Dir|=0xF0;//A4~A7 are output
	//direction of control pins
	LCD_CTRL_Dir|=(1<<RS)|(1<<RW)|(1<<E);
	LCD_CTRL&=~(1<<RW);//write mode
	_delay_ms(20);
	//initialize procedure
	LCD_command(0x33);
	LCD_command(0x32);
	LCD_command(0x28);
	LCD_command(0x0C);//display on, cursor off
	LCD_command(0x06);// entry mode
	LCD_command(0x01);//clear
}

void LCD_command(char cmd)
{
	//A4 ~A7 data pins of LCD
	LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0); //masking
	//RS PB1 RW PB2 E PB3
	LCD_CTRL&=~(1<<RS);
	LCD_CTRL|=(1<<E);
	_delay_us(10); // micro second
	LCD_CTRL&=~(1<<E);
	
	_delay_us(2000);
	LCD_PORT= (LCD_PORT & 0x0F) | (cmd << 4);
	LCD_CTRL|=(1<<E);
	_delay_us(10); // micro second
	LCD_CTRL&=~(1<<E);
	
	//execution time LCD command
	_delay_ms(10);
}


void LCD_char(char data)
{
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0); //masking
	LCD_CTRL|=(1<<RS);//data register
	LCD_CTRL|=(1<<E);
	_delay_us(10);
	LCD_CTRL&=~(1<<E);
	_delay_us(2000);
	LCD_PORT= (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL|=(1<<E);
	_delay_us(10); // micro second
	LCD_CTRL&=~(1<<E);
	_delay_ms(10);
}
void LCD_string(char* str)
{
	int i =0;
	while(str[i]!='\0')
	{
		LCD_char(str[i]);
		i++;
	}
}
