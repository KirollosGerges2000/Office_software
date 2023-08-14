#include <avr/interrupt.h>  // file.h  for driving interrupt
#include "MACROS.h"  //macros library
#include <util/delay.h>
unsigned char g_Interrupt_Flag = 0;
/*Interrupt service vector  must be active , when interrupt declared*/ 
ISR(INT0_vect)
{
	g_Interrupt_Flag = 1;
	process();

	
}
// External INT0 enable and configuration function
void INT0_Init(void)
{
		SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
		SREG  |= (1<<7);       // Enable interrupts by setting I-bit
      
	DDRD  &= (~(1<<2));  // Configure INT0/PD2 as input pin
	PORTD |= (1<<2);     // Enable the internal pull up resistor at PD2 pin
	GICR  |= (1<<6);    // Enable external interrupt pin INT0
	// Trigger INT0 with the rising edge

MCUCR |= (1<<1);
	MCUCR |= (1<<0);
}

 
void process(void)
{
	if(g_Interrupt_Flag==1)
	{
			LCD_Init();
			LCD_String("A person Enter");
			LCD_Command(0xC0);
			LCD_String("your Office !!");
			CLOCK ();
		
		for(unsigned char i=0 ;i<=1;i++)
		{
			OUTPUT_MODULE_ON(PORTC,2);
	TOGGLe_BIT(PORTA,3);
	_delay_ms(1500);
	OUPUT_MODULE_OFF(PORTC,2);
	TOGGLe_BIT(PORTA,3);
	TOGGLe_BIT(PORTC,0);
	_delay_ms(1500);
	
	OUTPUT_MODULE_ON(PORTC,7);
	TOGGLe_BIT(PORTA,3);
	_delay_ms(1500);
	OUPUT_MODULE_OFF(PORTC,7);
	TOGGLe_BIT(PORTA,3);
	TOGGLe_BIT(PORTC,0);
	_delay_ms(1500);
	
	OUTPUT_MODULE_ON(PORTD,3);
	TOGGLe_BIT(PORTA,3);
	_delay_ms(1500);
	OUPUT_MODULE_OFF(PORTD,3);
	TOGGLe_BIT(PORTA,3);
	TOGGLe_BIT(PORTC,0);
	_delay_ms(1500);
	
		}
	
LCD_Clear();
	
	g_Interrupt_Flag = 0;
	
	}
	
}