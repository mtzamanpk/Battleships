#include "stdbool.h"

struct Location {
	int c;
	int r;
};

struct Vessel {
	char name[20];
	bool sunk;
	unsigned int length;
	struct Location vesselLocations[5];
	bool hits[5];
};



void powerPeripherals(void);
void configureIO(void);
int turnOnLED(void);
void delay(void);
bool blueSwitchOn(void);
bool switch1On(void);
bool switch2On(void);
bool switch3On(void);
bool switch4On(void);
void AOn(bool);
void BOn(bool);
void COn(bool);
void DOn(bool);
void EOn(bool);
void FOn(bool);
void GOn(bool);
