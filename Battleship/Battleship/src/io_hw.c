#include "../include/io_hw.h"
#include "stm32f10x.h"
#include <stdbool.h>

void powerPeripherals()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
}
void configurePorts()
{
	GPIOA->CRL |= GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1 |		//A0 -- LED 0
								GPIO_CRL_MODE1_0 | GPIO_CRL_MODE1_1 |		//A1 -- LED 1
								GPIO_CRL_MODE4_0 | GPIO_CRL_MODE4_1;		//A4 -- LED 2
	
	GPIOA->CRL &= GPIO_CRL_CNF0_0 &~ GPIO_CRL_CNF0 &			//A0 -- LED 0 
								GPIO_CRL_CNF1_0 &~ GPIO_CRL_CNF1 &			//A1 -- LED 1
								GPIO_CRL_CNF4_0 &~ GPIO_CRL_CNF4;				//A4 -- LED 2
	
	GPIOB->CRL |= GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1;		//B0 -- LED 3
	
	GPIOB->CRL &= GPIO_CRL_CNF0_0 &~ GPIO_CRL_CNF0;				//B0 -- LED 3
	
	GPIOB->CRL |= GPIO_CRL_MODE4_0 | GPIO_CRL_MODE4_1 |		//B4 -- SWITCH 0
								GPIO_CRL_MODE6_0 | GPIO_CRL_MODE6_1;		//B6 -- SWITCH 1 
	
	GPIOB->CRL &= GPIO_CRL_CNF4_0 &~ GPIO_CRL_CNF4 &			//B4 -- SWITCH 0
								GPIO_CRL_CNF6_0 &~ GPIO_CRL_CNF6;				//B6 -- SWITCH 1
	
	GPIOB->CRH |= GPIO_CRH_MODE8_0 | GPIO_CRH_MODE8_1 |		//B9 -- SWITCH 3
								GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1;		//B8 -- SWITCH 2 
	
	GPIOB->CRH &= GPIO_CRH_CNF8_0 &~ GPIO_CRH_CNF8 &			//B8 -- SWITCH 2
								GPIO_CRH_CNF9_0 &~ GPIO_CRH_CNF9;				//B9 -- SWITCH 3
	
	
	
}

void displaySea(void)
{
		//Cant display the sea on our hardware
}