/*
 * LCD.c
 *
 * Created: 30-May-20 11:21:28 AM
 * Author : Mohamed Khaled Shell
 */ 

#include "lcd.h"
int main(void)
{
    /* Replace with your application code */
	LCD_init();
	LCD_command(0x80);
	LCD_string("shell");
    while (1) 
    {
    }
}

