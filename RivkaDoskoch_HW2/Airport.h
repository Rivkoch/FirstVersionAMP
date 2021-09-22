#pragma once
#include "general.h"

typedef struct 
{
	char* name;
	char* country;
	char IATA[CODELEN + 1];
} Airport;

int		isSameAirport(const Airport* pA1, const Airport* pA2);
int		isSameCode(const Airport* pA, const char* IATA);

void	initAirport(Airport* pA);
void	initCode(char* IATA);
void	printAirport(Airport* pA);
void	freeAirport(Airport* pA);