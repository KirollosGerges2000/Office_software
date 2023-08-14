
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "lcd 4_bits.h"
void LCD_Command(unsigned char cmnd)
{
	
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (cmnd & 0xF0);/* Sending upper nibble */
	LCD_Command_Port &= ~ (1<<RW);		/* RS=0, command reg. */
	LCD_Command_Port &= ~(1<<RS);		/* RS=0, command reg. */
	LCD_Command_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (cmnd << 4);/* Sending lower nibble */
	LCD_Command_Port |= (1<<EN);
	_delay_us(1);
	LCD_Command_Port &= ~ (1<<EN);
	_delay_ms(10);
}

void LCD_Char (unsigned char char_data)
{
	
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (char_data & 0xF0);/* Sending upper nibble */
	LCD_Command_Port &= ~ (1<<RW);		/* RS=0, command reg. */
	LCD_Command_Port |= (1<<RS);		/* RS=0, command reg. */
	LCD_Command_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (char_data << 4);/* Sending lower nibble */
	LCD_Command_Port |= (1<<EN);
	_delay_us(1);
	LCD_Command_Port &= ~ (1<<EN);
	_delay_ms(10);
}

void LCD_Init (void)
{
	LCD_Data_Dir |= 0xF0;
	LCD_Command_Dir |= 0b00001110;
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
	_delay_ms(20);
	
}

void LCD_String (char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);
	LCD_String(str);
}

void LCD_Clear()
{
	LCD_Command (0x01);
	LCD_Command (0x80);
}

void lcd_into_string(char data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD_String(buff);
}