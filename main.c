/*
 * my Smart office.c
 *
 * Created: 8/12/2023 9:27:12 PM
 * Author : Kirollos Gerges
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "MACROS.h"
#include "DIO.h"
#include "lcd 4_bits.h"
#include "interrupt.h"

uint16 hr=2;
uint16 min=8;
uint16 sec=0;

int main(void)
{
	 INT0_Init();           // Enable and configure external INT0
	
	 
    /* Replace with your application code */
	INPUT_MODULE(DDRD,2);
		INPUT_MODULE(DDRB,1);    //upper Button 
			INPUT_MODULE(DDRB,0);//Lower Button
	OUTPUT_MODULE(DDRC,7);
		OUTPUT_MODULE(DDRC,2);
			OUTPUT_MODULE(DDRD,3);
					OUTPUT_MODULE(DDRC,0);
	OUTPUT_MODULE(DDRA,3);
	
	OUPUT_MODULE_OFF(PORTC,7);
	OUPUT_MODULE_OFF(PORTC,2);
	OUPUT_MODULE_OFF(PORTD,3);
	OUPUT_MODULE_OFF(PORTA,3);
	OUPUT_MODULE_OFF(PORTC,0);
	
	
		
    while (1) 
    {

		


					OUPUT_MODULE_OFF(PORTC,7);
			OUPUT_MODULE_OFF(PORTC,2);
			OUPUT_MODULE_OFF(PORTD,2);
			OUPUT_MODULE_OFF(PORTA,3);
			OUPUT_MODULE_OFF(PORTC,0);
		INTRODUCTORY_OFFICE();	
			 Clock_process();
			setting_clock();
		
			
		
    }
	return 0;
}

void CLOCK (void)
{
_delay_ms(10000);
sec=sec+3;
if(sec>=59)	
{
	sec=0;
	min++;
}
else if(min>=59)
{
	min=0;
	hr++;
}

}
void setting_clock(void)
{
	
	while(READBIT_BIT(PINB,0))
	{
		 Clock_process();
		
		 if (READBIT_BIT(PINB,0))
		{
			min=min+5;
		}
	
			
		
		_delay_ms(2000);
	}
	
}
		void Clock_process(void)
		{
			LCD_Init();
			LCD_String("DigitalClock24hr");
			LCD_Command(0xC0);
			CLOCK ();
			if(hr<10 && min<10 && sec<10)  //000
			{
				LCD_String("0");lcd_into_string(hr); LCD_String(":"); LCD_String("0");lcd_into_string(min);LCD_String(":");LCD_String("0"); lcd_into_string(sec);
				
			}
			else if (hr>=10 && min<10 && sec<10) //100
			{
				lcd_into_string(hr); LCD_String(":"); LCD_String("0");lcd_into_string(min);LCD_String(":");LCD_String("0"); lcd_into_string(sec);
			}
			
			else if (hr<10 && min>=10 && sec<10) //010
			{
				LCD_String("0"); lcd_into_string(hr); LCD_String(":"); lcd_into_string(min);LCD_String(":");LCD_String("0"); lcd_into_string(sec);
			}
			
			else if (hr<10 && min<10 && sec>=10) //001
			{
				LCD_String("0");  lcd_into_string(hr); LCD_String(":");LCD_String("0"); lcd_into_string(min);LCD_String(":"); lcd_into_string(sec);
			}
			
			else if (hr<10 && min>=10 && sec>=10) //011
			{
				LCD_String("0");lcd_into_string(hr); LCD_String(":"); lcd_into_string(min);LCD_String(":"); lcd_into_string(sec);
			}
			
			else if (hr>=10 && min<10 && sec>=10) //101
			{
				lcd_into_string(hr); LCD_String(":"); LCD_String("0");lcd_into_string(min);LCD_String(":");	 lcd_into_string(sec);
			}
			else if (hr>=10 && min>=10 && sec<10) //110
			{
				lcd_into_string(hr); LCD_String(":"); lcd_into_string(min);LCD_String(":");	LCD_String("0"); lcd_into_string(sec);
			}
		
			else //111
			{
				lcd_into_string(hr); LCD_String(":"); lcd_into_string(min);LCD_String(":"); lcd_into_string(sec);
			}
			
			_delay_ms(15000);
			
			LCD_Clear();
		}
		void INTRODUCTORY_OFFICE(void)
		{
		
			LCD_Init();
	LCD_String("  Eng/Kirollos  ");
	LCD_Command(0xC0);
	LCD_String("MechaEngineering");
	_delay_ms(15000);
	LCD_Clear();
	
		}
	