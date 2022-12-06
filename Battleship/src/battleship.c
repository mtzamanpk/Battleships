#include "../include/battleship.h"
#include "stm32f10x.h"
#include "stdbool.h"
#include <stdio.h>
#include <string.h>
#ifdef HARDWARE
#include "../include/io_hw.h"
#else
#include "../include/io.h"
#endif

void setupShips(void);


static struct Vessel vessels[5];

int main()
{
	bool hit = false;
	bool game = true;
	int number = 0;
	int row = 0;
	int column = 0;
	
	powerPeripherals();
	configureIO();
	
	setupShips();

	while (game)
	{
		
			AOn(true);	//displays all the horizontal lines for row
			BOn(false);
			COn(false);
			DOn(true);
			EOn(false);
			FOn(false);
			GOn(true);
			delay();
			while(blueSwitchOn() == false)	//while look to store the row given
			{
					number = turnOnLED();
			}
			row = number;
			
			AOn(false);	//displays all the vertical lines signifying column
			BOn(true);
			COn(true);
			DOn(false);
			EOn(true);
			FOn(true);
			GOn(false);
			delay();
		
		
			while(blueSwitchOn() == false)	//while loop to store the column given
			{
					number = turnOnLED();
			}
			
			column = number;
			
			
		
		for(int i = 0; i < 5; i++)	//i for vessels
		{
			for(int j = 0; j < 5; j++)	//j for vesselLocation storing
			{
				if(vessels[i].vesselLocations[j].r == row && vessels[i].vesselLocations[j].c == column)
				{
					hit = true;	//checks for the coordinate that we sent via blue switch and marks it as hit, and tells you if hit
					vessels[i].hits[j] = true;
					AOn(false);
					BOn(true);
					COn(true);
					DOn(false);
					EOn(true);
					FOn(true);
					GOn(true);
					delay();
				
					if(vessels[i].hits[0] == true && vessels[i].hits[1] == true && vessels[i].hits[2] == true && vessels[i].hits[3] == true && vessels[i].hits[4] == true)
					{
						vessels[i].sunk = true;	//checks for hits on the ship, if enough hits on the ship to sink, then it will show S for sink
							AOn(true);
							BOn(false);
							COn(true);
							DOn(true);
							EOn(false);
							FOn(true);
							GOn(true);
						delay();
					}
					if(vessels[0].sunk == true && vessels[1].sunk == true && vessels[2].sunk == true && vessels[3].sunk == true && vessels[4].sunk == true)	
					{
						game = false;	//the if statement checks to see if all of the ships have sunk, if so then game over, and 7 segment display will show FF simbolizing game over
						AOn(true);
						BOn(false);
						COn(false);
						DOn(false);
						EOn(true);
						FOn(true);
						GOn(true);
						delay();
						AOn(true);	//displays second F
						BOn(false);
						COn(false);
						DOn(false);
						EOn(true);
						FOn(true);
						GOn(true);
						delay();
					}
					break;
				}
			}
		}
			if(hit == false)	//if its a miss then display 0 for miss
			{
				AOn(true);
				BOn(true);
				COn(true);
				DOn(true);
				EOn(true);
				FOn(true);
				GOn(false);
				delay();
			}
	}

	return 0;
}


void setupShips(void)
{
	strcpy(vessels[0].name, "Destroyer");	//destroyer ship 
	vessels[0].sunk = false;
	vessels[0].length = 2;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 2;
	vessels[0].vesselLocations[1].c = 2;
	vessels[0].vesselLocations[1].r = 3;
	vessels[0].vesselLocations[2].c = -1;	//set to negative one as it is a not required coordinate since its only a 2x1 ship
	vessels[0].vesselLocations[2].r = -1;
	vessels[0].vesselLocations[3].c = -1;
	vessels[0].vesselLocations[3].r =	-1;
	vessels[0].vesselLocations[4].c = -1;
	vessels[0].vesselLocations[4].r = -1;
	vessels[0].hits[0] = false;	//set to false as these are a part of the ship that we can hit
	vessels[0].hits[1] = false;
	vessels[0].hits[2] = true;
	vessels[0].hits[3] = true;	//set to true as we are emulating that this ship is not 5x1
	vessels[0].hits[4] = true;
	
	
	strcpy(vessels[1].name, "Submarine");
	vessels[1].sunk = false;
	vessels[1].length = 3;
	vessels[1].vesselLocations[0].c = 4;
	vessels[1].vesselLocations[0].r = 4;
	vessels[1].vesselLocations[1].c = 4;
	vessels[1].vesselLocations[1].r = 3;
	vessels[1].vesselLocations[2].c = 4;
	vessels[1].vesselLocations[2].r = 2;
	vessels[1].vesselLocations[3].c = -1;
	vessels[1].vesselLocations[3].r =	-1;
	vessels[1].vesselLocations[4].c = -1;
	vessels[1].vesselLocations[4].r = -1;
	vessels[1].hits[0] = false;
	vessels[1].hits[1] = false;
	vessels[1].hits[2] = false;
	vessels[1].hits[3] = true;
	vessels[1].hits[4] = true;
	
	strcpy(vessels[2].name, "Cruiser");
	vessels[2].sunk = false;
	vessels[2].length = 3;
	vessels[2].vesselLocations[0].c = 5;
	vessels[2].vesselLocations[0].r = 5;
	vessels[2].vesselLocations[1].c = 5;
	vessels[2].vesselLocations[1].r = 4;
	vessels[2].vesselLocations[2].c = 5;
	vessels[2].vesselLocations[2].r = 3;
	vessels[2].vesselLocations[3].c = -1;
	vessels[2].vesselLocations[3].r =	-1;
	vessels[2].vesselLocations[4].c = -1;
	vessels[2].vesselLocations[4].r = -1;
	vessels[2].hits[0] = false;
	vessels[2].hits[1] = false;
	vessels[2].hits[2] = false;
	vessels[2].hits[3] = true;
	vessels[2].hits[4] = true;
	
	strcpy(vessels[3].name, "Battleship");
	vessels[3].sunk = false;
	vessels[3].length = 4;
	vessels[3].vesselLocations[0].c = 6;
	vessels[3].vesselLocations[0].r = 6;
	vessels[3].vesselLocations[1].c = 6;
	vessels[3].vesselLocations[1].r = 5;
	vessels[3].vesselLocations[2].c = 6;
	vessels[3].vesselLocations[2].r = 4;
	vessels[3].vesselLocations[3].c = 6;
	vessels[3].vesselLocations[3].r =	3;
	vessels[3].vesselLocations[4].c = -1;
	vessels[3].vesselLocations[4].r = -1;
	vessels[3].hits[0] = false;
	vessels[3].hits[1] = false;
	vessels[3].hits[2] = false;
	vessels[3].hits[3] = false;
	vessels[3].hits[4] = true;
	
	strcpy(vessels[4].name, "Carrier");
	vessels[4].sunk = false;
	vessels[4].length = 4;
	vessels[4].vesselLocations[0].c = 7;
	vessels[4].vesselLocations[0].r = 7;
	vessels[4].vesselLocations[1].c = 7;
	vessels[4].vesselLocations[1].r = 6;
	vessels[4].vesselLocations[2].c = 7;
	vessels[4].vesselLocations[2].r = 5;
	vessels[4].vesselLocations[3].c = 7;
	vessels[4].vesselLocations[3].r =	4;
	vessels[4].vesselLocations[4].c = 7;
	vessels[4].vesselLocations[4].r = 3;
	vessels[4].hits[0] = false;
	vessels[4].hits[1] = false;
	vessels[4].hits[2] = false;
	vessels[4].hits[3] = false;
	vessels[4].hits[4] = false;
}
void powerPeripherals()
{
	//powering peripherals 
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN |  RCC_APB2ENR_IOPCEN;
}

void configureIO()
{
	GPIOA->CRL |=  GPIO_CRL_MODE5_0 |  GPIO_CRL_MODE5_1;	// turning on greed led on stm board
	GPIOA->CRL &= ~GPIO_CRL_CNF5_0 &~ GPIO_CRL_CNF5_1;
	
	GPIOA->CRL |=  GPIO_CRL_MODE0_0 |  GPIO_CRL_MODE0_1 | GPIO_CRL_MODE1_0 |  GPIO_CRL_MODE1_1 | GPIO_CRL_MODE4_0 |  GPIO_CRL_MODE4_1;	//turning on A, B, C on 7seg display
	GPIOA->CRL &= ~GPIO_CRL_CNF0_0 &~ GPIO_CRL_CNF0_1 &~ GPIO_CRL_CNF1_0 &~ GPIO_CRL_CNF1_1 &~ GPIO_CRL_CNF4_0 &~ GPIO_CRL_CNF4_1;
	
	GPIOA->CRL |=  GPIO_CRL_MODE6_0 |  GPIO_CRL_MODE6_1 | GPIO_CRL_MODE7_0 |  GPIO_CRL_MODE7_1;	//setting up F, G on 7seg display
	GPIOA->CRL &= ~GPIO_CRL_CNF6_0 &~ GPIO_CRL_CNF6_1 &~ GPIO_CRL_CNF7_0 &~ GPIO_CRL_CNF7_1;
	
	GPIOA->CRH |=  GPIO_CRH_MODE9_0 |  GPIO_CRH_MODE9_1; //setting up E on 7seg display
	GPIOA->CRH &= ~GPIO_CRH_CNF9_0 &~ GPIO_CRH_CNF9_1;
	
	GPIOB->CRL |=  GPIO_CRL_MODE0_0 |  GPIO_CRL_MODE0_1;	//setting up D on 7seg display, 
	GPIOB->CRL &= ~GPIO_CRL_CNF0_0 &~ GPIO_CRL_CNF0_1;
	
	GPIOB->CRL |=   GPIO_CRL_CNF4_0;	//setting up switch 1
	GPIOB->CRL &= ~GPIO_CRL_MODE4_0 &~ GPIO_CRL_MODE4_1 &~ GPIO_CRL_CNF4_1;
	
	GPIOB->CRL |=  GPIO_CRL_CNF6_0;	//setting up switch 2
	GPIOB->CRL &= ~GPIO_CRL_MODE6_0 &~ GPIO_CRL_MODE6_1 &~  GPIO_CRL_CNF6_1;
	
	GPIOB->CRH |=  GPIO_CRH_CNF8_0 | GPIO_CRH_CNF9_0;	//setting up switch 3 and 4 
	GPIOB->CRH &= ~GPIO_CRH_MODE8_0 &~ GPIO_CRH_MODE8_1 &~ GPIO_CRH_CNF8_1 &~ GPIO_CRH_MODE9_0 &~ GPIO_CRH_MODE9_1 &~ GPIO_CRH_CNF9_1;	
	
	GPIOC->CRH |=  GPIO_CRH_CNF13_0;	//setting up blue switch
	GPIOC->CRH &= ~GPIO_CRH_MODE13_0 &~ GPIO_CRH_MODE13_1 &~  GPIO_CRH_CNF13_1;
	
}

int turnOnLED()	//turning on 7 Seg
{
	if(switch1On() == false && switch2On() == false && switch3On() == false && switch4On()	== false) // 0000 - 0
	{
		AOn(true);	//displays 0 when nothing is on
		BOn(true);
		COn(true);
		DOn(true);
		EOn(true);
		FOn(true);
		GOn(false);
		return 0;		//returns 0 as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == false && switch3On() == false && switch4On()	== false) // 0001 - 1
	{
		AOn(false); //displays 1 when 0001 is on
		BOn(true);
		COn(true);
		DOn(false);
		EOn(false);
		FOn(false);
		GOn(false);
		return 1;		//returns 1 as that is the number being displayed
	}
	if(switch1On() == false && switch2On() == true && switch3On() == false && switch4On()	== false) //0010 - 2
	{
		AOn(true); //displays 2 when 0010 is on
		BOn(true);
		COn(false);
		DOn(true);
		EOn(true);
		FOn(false);
		GOn(true);
		return 2;		//returns 2 as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == true && switch3On() == false && switch4On()	== false) //0011 - 3
	{
		AOn(true); //displays 3 when 0011 is on
		BOn(true);
		COn(true);
		DOn(true);
		EOn(false);
		FOn(false);
		GOn(true);
		return 3;		//returns 3 as that is the number being displayed
	}
	if(switch1On() == false && switch2On() == false && switch3On() == true && switch4On()	== false) // 0100 - 4
	{
		AOn(false); //displays 4 when 0100 is on
		BOn(true);
		COn(true);
		DOn(false);
		EOn(false);
		FOn(true);
		GOn(true);
		return 4;		//returns 4 as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == false && switch3On() == true && switch4On()	== false) // 0101 - 5
	{
		AOn(true);  //displays 5 when 0101 is on
		BOn(false);
		COn(true);
		DOn(true);
		EOn(false);
		FOn(true);
		GOn(true);
		return 5;		//returns 5 as that is the number being displayed
	}
	if(switch1On() == false && switch2On() == true && switch3On() == true && switch4On()	== false) // 0110 - 6
	{
		AOn(true);	//displays 6 when 0110 is on
		BOn(false);
		COn(true);
		DOn(true);
		EOn(true);
		FOn(true);
		GOn(true);
		return 6;		//returns 6 as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == true && switch3On() == true && switch4On()	== false) // 0111 - 7
	{
		AOn(true);	//displays 7 when 0111 is on
		BOn(true);
		COn(true);
		DOn(false);
		EOn(false);
		FOn(false);
		GOn(false);
		return 7;		//returns 7 as that is the number being displayed
	}
		if(switch1On() == false && switch2On() == false && switch3On() == false && switch4On()	== true) // 1000 - 8
	{
		AOn(true);	//displays 8 when 1000 is on
		BOn(true);
		COn(true);
		DOn(true);
		EOn(true);
		FOn(true);
		GOn(true);
		return 8;		//returns 8 as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == false && switch3On() == false && switch4On()	== true) // 1001 - 9
	{
		AOn(true);	//displays 9 when 1001 is on
		BOn(true);
		COn(true);
		DOn(true);
		EOn(false);
		FOn(true);
		GOn(true);
		return 9;		//returns 8 as that is the number being displayed
	}
	if(switch1On() == false && switch2On() == true && switch3On() == false && switch4On()	== true) // 1010 - 10 - A
	{
		AOn(true);	//displays A when 1010 is on
		BOn(true);
		COn(true);
		DOn(false);
		EOn(true);
		FOn(true);
		GOn(true);
		return 10;		//returns A as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == true && switch3On() == false && switch4On()	== true) // 1011 - 11 - B
	{
		AOn(false);	//displays B when 1011 is on
		BOn(false);
		COn(true);
		DOn(true);
		EOn(true);
		FOn(true);
		GOn(true);
		return 11;		//returns B as that is the number being displayed
	}
	if(switch1On() == false && switch2On() == false && switch3On() == true && switch4On()	== true) // 1100 - 12 - C
	{
		AOn(true);	//displays C when 1100 is on
		BOn(false);
		COn(false);
		DOn(true);
		EOn(true);
		FOn(true);
		GOn(false);
		return 12;			//returns C as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == false && switch3On() == true && switch4On()	== true) // 1101 - 13 - D
	{
		AOn(false);	//displays D when 1101 is on
		BOn(true);
		COn(true);
		DOn(true);
		EOn(true);
		FOn(false);
		GOn(true);
		return 13;		//returns D as that is the number being displayed
	}
	if(switch1On() == false && switch2On() == true && switch3On() == true && switch4On()	== true) // 1110 - 14 - E
	{
		AOn(true);	//displays E when 1110 is on
		BOn(false);
		COn(false);
		DOn(true);
		EOn(true);
		FOn(true);
		GOn(true);
		return 14;		//returns E as that is the number being displayed
	}
	if(switch1On() == true && switch2On() == true && switch3On() == true && switch4On()	== true) // 1111 - 15 - F
	{
		AOn(true);	//displays F when 1111 is on
		BOn(false);
		COn(false);
		DOn(false);
		EOn(true);
		FOn(true);
		GOn(true);
		return 15;		//returns F as that is the number being displayed
	}
	return 0;
}

bool blueSwitchOn()	//enabling blue switch functionality 
{
	volatile unsigned int regIDR = GPIOC->IDR;	//setting up blue switch
	regIDR &= GPIO_IDR_IDR13;
	
	if(regIDR == GPIO_IDR_IDR13)
		return false;
	else
		return true;
}
bool switch1On()	//enabling switch 1 functionality 
{
	volatile unsigned int regIDR = GPIOB->IDR;	//setting up switch 1 on 4 way switch
		regIDR &= GPIO_IDR_IDR4;
	
	if(regIDR == GPIO_IDR_IDR4)
		return false;
	else
		return true;
}
bool switch2On()	//enabling switch 2 functionality
{
	volatile unsigned int regIDR = GPIOB->IDR; //setting up switch 2 on 4 way switch
		regIDR &= GPIO_IDR_IDR6;
	
	if(regIDR == GPIO_IDR_IDR6)
		return false;
	else
		return true;
}

bool switch3On()	//enabling switch 3 functionality
{
	volatile unsigned int regIDR = GPIOB->IDR;	//setting up switch 3 on 4 way switch
		regIDR &= GPIO_IDR_IDR8;
	
	if(regIDR == GPIO_IDR_IDR8)
		return false;
	else
		return true;
}

bool switch4On()	//enabling switch 4 functionality
{
	volatile unsigned int regIDR = GPIOB->IDR;	//setting up switch 4 on 4 way switch
		regIDR &= GPIO_IDR_IDR9;
	
	if(regIDR == GPIO_IDR_IDR9)
		return false;
	else
		return true;
	
}

void delay()	//delay function for after we display something, it delays before setting another number
{
	
	unsigned volatile int c, d;
   
   for (c = 1; c <= 3000; c++)
       for (d = 1; d <= 3000; d++)
       {}
}



void AOn(bool input)	//turning on the A segment on the 7 segment display
{
	if(input == true)
	{
		GPIOA->ODR |=  GPIO_ODR_ODR0;	
	}
	else
	{
		GPIOA->ODR &= ~(uint32_t)GPIO_ODR_ODR0;
	}
}
void BOn(bool input)	//turning on the B segment on the 7 segment display
{
	if(input == true)
	{
		GPIOA->ODR |=  GPIO_ODR_ODR1;
	}
	else
	{
		GPIOA->ODR &= ~(uint32_t)GPIO_ODR_ODR1;
	}
}
void COn(bool input)	//turning on the C segment on the 7 segment display
{
	if(input == true)
	{
		GPIOA->ODR |=  GPIO_ODR_ODR4;
	}
	else
	{
		GPIOA->ODR &= ~(uint32_t)GPIO_ODR_ODR4;
	}
}
void DOn(bool input)	//turning on the D segment on the 7 segment display
{
	if(input == true)
	{
		GPIOB->ODR |=  GPIO_ODR_ODR0;
	}
	else
	{
		GPIOB->ODR &= ~(uint32_t)GPIO_ODR_ODR0;
	}
}
void EOn(bool input)	//turning on the E segment on the 7 segment display
{
	if(input == true)
	{
		GPIOA->ODR |=  GPIO_ODR_ODR9;
	}
	else
	{
		GPIOA->ODR &= ~(uint32_t)GPIO_ODR_ODR9;
	}
}
void FOn(bool input)	//turning on the F segment on the 7 segment display
{
	if(input == true)
	{
		GPIOA->ODR |=  GPIO_ODR_ODR6;
	}
	else
	{
		GPIOA->ODR &= ~(uint32_t)GPIO_ODR_ODR6;
	}
}
void GOn(bool input)	//turning on the G segment on the 7 segment display
{
	if(input == true)
	{
		GPIOA->ODR |=  GPIO_ODR_ODR7;
	}
	else
	{
		GPIOA->ODR &= ~(uint32_t)GPIO_ODR_ODR7;
	}
}