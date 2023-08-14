//Macros Library 
//Author:Kirollos Gerges 
#ifndef _MACROS_H
#define _MACROS_H
#define SET_BIT(REG,BIT_N) REG|=(1<<BIT_N)
#define CLR_BIT(REG,BIT_N) REG&=~(1<<BIT_N)
#define TOGGLe_BIT(REG,BIT_N) REG=REG^(1<<BIT_N) 
#define READBIT_BIT(REG,BIT_N) (REG>>BIT_N)&1
#define INPUT_BIT(PIN_SYMBOL,BIT_N)  PIN_SYMBOL&(1<<BIT_N)  //to read  signal from the user
#define OUTPUT_MODULE_ON(PORT_SYMBOL,BIT_N)   PORT_SYMBOL|=1<<BIT_N; //initially output module is oN or turn it On.
#define OUPUT_MODULE_OFF(PORT_SYMBOL,BIT_N)   PORT_SYMBOL&=~(1<<BIT_N); //initially output module is off or turn it off.


#endif