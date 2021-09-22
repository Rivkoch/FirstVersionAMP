#pragma once
#include "AirportManager.h"
#include "date.h"

typedef struct 
{
	char	sourceIATA[CODELEN + 1];
	char	destIATA[CODELEN + 1];
	float	seatCost;
	Date*	date;
}Flight;

int		isCurretDests(Flight* pF, char* sourceIATA, char* destIATA);
int		numOfFlights(Flight** arr, int size, char* sourceIATA, char* destIATA);

int	initFlight(Flight* pF, AirportManager* pAM);
void	printFlight(Flight* pF);
void	freeFlight(Flight* pF);


