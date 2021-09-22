#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airline.h"




int addFlight(Airline* pAirline, AirportManager* airportMan)
{
	Flight* pFlight = (Flight*)malloc(sizeof(Flight));
	if (!pFlight)
		return 0;

	if (!initFlight(pFlight, airportMan))
	{
		freeFlight(pFlight); 
		printf("can't initialize flight\n");
		return 0;
	}

	pAirline->allFlights = (Flight**)realloc(pAirline->allFlights, sizeof(Flight*) * ((pAirline->numOfFlights) + 1));
	pAirline->allFlights[pAirline->numOfFlights] = pFlight;
	pAirline->numOfFlights++;
	printf("The flight successfully added.\n");
	return 1;
}

int howManyFlightsInLine(Airline* pAirline)
{
	char sourceTempCode[CODELEN + 1];
	char destTempCode[CODELEN + 1];
	//fflush(stdin); getchar();

	if (pAirline->numOfFlights == 0)
	{
		printf("There is no flights");
		return 0;
	}

	printf("Enter source Code: ");
	initCode(sourceTempCode);
	//getchar();
	printf("Enter destination Code: ");
	initCode(destTempCode);

	int count = numOfFlights((Flight**)pAirline->allFlights, pAirline->numOfFlights, sourceTempCode, destTempCode);
	if (count == 0)
		printf("There is no flights by the codes that setted.");
	else
		printf("from port %s to port %s: %d flights\n", sourceTempCode, destTempCode, count);
	return count;
}

int initAirline(Airline* pAirline)
{
	
	pAirline->airlineName = getStrExactName("Enter airline name");
	pAirline->allFlights = NULL;
	pAirline->numOfFlights = 0;
	
	char* airlineCountry, *city, *street;
	airlineCountry = (char*)malloc(sizeof(char));
	if(!airlineCountry)
		return 0;
	city = (char*)malloc(sizeof(char));
	if (!city)
		return 0;
	street = (char*)malloc(sizeof(char));
	if (!street)
		return 0;

	airlineCountry = getStrExactName("Enter Airline country");
	city = getStrExactName("Enter Airline city");
	street = getStrExactName("Enter Airline street");
	if(!setTheAddress(airlineCountry, city, street))
		return 0;
	else
		pAirline->address = setTheAddress(airlineCountry, city, street);

	return 1;
}

char* setTheAddress(char * airlineCountry, char * city, char * street)
{
	int countryLen = strlen(airlineCountry);
	int cityLen = strlen(city);
	int streetLen = strlen(street);

	char* allTheAddress = (char*)malloc((countryLen + cityLen + streetLen) * sizeof(char));
	if (!allTheAddress)
		return NULL;
	
	theWord(allTheAddress,  airlineCountry);

	theWord(allTheAddress, city);

	theWord(allTheAddress, street);

	strcpy(allTheAddress, airlineCountry);
	strcat(allTheAddress, city);
	strcat(allTheAddress, street);

	
	return allTheAddress;
}

void theWord(char* allTheAddress, char* original)
{
	int numOfWords, counter = 0;
	char tempName[225], newName[225];
	newName[0] = '\0';

	char *newWord;
	strcpy(tempName, original);
	numOfWords = countWords(tempName);

	newWord = strtok(original, DELIMITERS);

	while (newWord != NULL && counter < numOfWords)
	{
		//case of only 1 word in the name
		if (numOfWords == 1)
		{
			newWord[0] = toupper(newWord[0]);
			strcpy(original, newWord);
			return;
		}
		//case of odd word
		if (strlen(newWord) % 2 != 0)
		{
			oddWordChange(newWord); //check
		}
		//the new word is the last in the name
		else if (counter == numOfWords - 1)
		{
			newWord[0] = toupper(newWord[0]);
			strcat(newName, newWord);
			break;
		}

		newWord[0] = tolower(newWord[0]);
		strcat(newName, newWord);

		if ((counter+1) == numOfWords)
		{
			strcat(newName, "#");
		}
		else
		{
			strcat(newName, "_");
		}
		counter++;
		newWord = strtok(NULL, DELIMITERS);
	}
	strcpy(original, newName);
}


int countWords(char *tempName) 
{
	int numOfWords = 0;
	char *word;
	word = strtok(tempName, DELIMITERS);
	while (word) {
		numOfWords++;
		word = strtok(NULL, DELIMITERS);
	}
	return numOfWords;
}

void oddWordChange(char *oddWord)
{
	int lenOddWord = strlen(oddWord), i;
	for (i = 0; i < lenOddWord; ++i)
	{
		if (i % 2 == 0)
			oddWord[i] = tolower(oddWord[i]);
		else
			oddWord[i] = toupper(oddWord[i]);
	}
}



void printAirline(const Airline * pAirline)
{
	printf("The Airlin %s based in: %s\n", pAirline->airlineName, pAirline->address);
	printf("has %d flights : \n",  pAirline->numOfFlights);
	for (int i = 0; i < pAirline->numOfFlights; i++)
	{
		printFlight(pAirline->allFlights[i]);
	}
}


void freeAirline(Airline* airline)
{
	free(airline->airlineName);
	for (int i = 0; i < airline->numOfFlights; i++)
	{
		freeFlight(airline->allFlights[i]);
	}
	free(airline->allFlights);
}