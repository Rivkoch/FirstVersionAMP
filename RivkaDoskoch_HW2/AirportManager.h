#pragma once
#include "Airport.h"

typedef struct
{
	Airport* airporstArr;
	int numOfPorts;
}AirportManager;

int		addAirport(AirportManager * pAM);
Airport*	findPortByCode(AirportManager* pAM, char* IATA);

int			initAirportManager(AirportManager* pAM);
void		printAirportManager(AirportManager* pAM);
void		freeAirportManager(AirportManager* pAM);