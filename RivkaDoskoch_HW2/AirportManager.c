#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirportManager.h"

int addAirport(AirportManager * pAM)
{
	Airport* pA = (Airport*)malloc(sizeof(Airport));
	if (!pA)
		return 0;

	printf("\n");
	initAirport(pA);
	initCode(pA->IATA);
	
	if (pAM->airporstArr != NULL)
	{
		while(findPortByCode(pAM, pA->IATA) != NULL)
			{
				printf("This code is already exist --> try again.\n");
				initCode(pA->IATA);
			}
	}
	

	pAM->airporstArr = (Airport*)realloc(pAM->airporstArr, sizeof(Airport)*((pAM->numOfPorts) + 1));
	pAM->airporstArr[pAM->numOfPorts] = *pA;
	pAM->numOfPorts++;
	return 1;
}

Airport * findPortByCode(AirportManager * pAM, char * IATA)
{
	for (int i = 0; i < pAM->numOfPorts; i++)
	{
		if (isSameCode(&pAM->airporstArr[i], IATA))
			return &pAM->airporstArr[i];
	}

	return NULL;
}

int initAirportManager(AirportManager* pAM)
{
	pAM->numOfPorts = 0;
	int amount=-1;
	
	pAM->airporstArr = NULL;

	while (amount<2)
	{
		printf("Enter how many aiports: ");
		scanf("%d", &amount);
		getchar(); 

		if (amount < 2)
			printf("\ninvalid number, for create flights you need at least 2 Airports --> try again\n");
	}
	

	pAM->airporstArr = (Airport*)malloc(amount * sizeof(Airport));
	if (!pAM->airporstArr)
		return 0;

	for (int i = 0; i < amount; i++)
	{
		if (!addAirport(pAM))
			return 0;
		
	}
	
	printf("\n%d airports successfully added.\n", pAM->numOfPorts);
	return 1;
}

void printAirportManager(AirportManager* pAM)
{
	printf("Airport Manager has: %d airports:\n", pAM->numOfPorts);
	
	for (int i = 0; i < pAM->numOfPorts; i++)
	{
		printAirport(&pAM->airporstArr[i]);
	}
	
}

void	freeAirportManager(AirportManager* pAM)
{
	for (int i = 0; i < pAM->numOfPorts; i++)
	{
		freeAirport(&pAM->airporstArr[i]);
	}
	free(pAM->airporstArr);
}