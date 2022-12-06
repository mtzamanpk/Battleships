#include "../include/battleship.h"
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
	
	setupShips();
	
	displaySea();
	
	return 0;
}


void setupShips(void)
{
	strcpy(vessels[0].name, "Carrier");
	vessels[0].sunk = false;
	vessels[0].length = 5;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 2;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 3;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 4;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 5;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 6;
	
}
