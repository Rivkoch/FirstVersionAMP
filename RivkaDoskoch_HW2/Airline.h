#pragma once
#include "Flight.h"
#define DELIMITERS " "


typedef struct
{
	char* airlineName;
	char* address;
	int   numOfFlights;
	Flight** allFlights;

}Airline;

int addFlight(Airline* pAirline, AirportManager* airportMan);
int howManyFlightsInLine(Airline* pAirline);


int initAirline(Airline* pAirline);
char* setTheAddress(char* airlineCountry, char* city, char* street);
void theWord(char* allTheAddress, char* original);
int countWords(char *tempName);
void oddWordChange(char* oddWord);

void printAirline(const Airline* pAirline);
void freeAirline(Airline* airline);

