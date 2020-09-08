#include "stm32f4xx.h"                  // Device header
//PA0 ->AHB1
//ADC123_IN0

//connect potentiometer and check

int analogValue;  

int main(void)
{
	RCC->AHB1ENR |= (1<<0);		//ENABLE CLOCK FOR PORT A
	GPIOA->MODER |= (3<<0);  //SETTING PA0 TO ANALOG
	
	//CONFIGURE ADC1
	RCC->APB2ENR |= (1<<8);  //ADC1 CLOCK ENABLED
	ADC1->CR2  = 0	;    		 //DISABLE ADC1
	ADC1->SQR1 = 1;
	ADC1->CR2  |= (1<<0);			//ENABLE ADC1

		while(1)
		{
			ADC1->CR2 |= (1<<30);
			while(!(ADC1->SR & 2));
			analogValue = ADC1->DR ;  
		}

}