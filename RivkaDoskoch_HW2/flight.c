#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<float.h>
#include "flight.h"

int		isCurretDests(Flight* pF, char* sourceIATA, char* destIATA)
{
	if (strcmp(sourceIATA, pF->sourceIATA) && strcmp(destIATA, pF->destIATA))
		return 1;

	return 0;
}

int		numOfFlights(Flight** arr, int size, char* sourceIATA, char* destIATA)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (isCurretDests(arr[i], sourceIATA, destIATA))
			count++;
	}

	return count;
}

int	initFlight(Flight* pF, AirportManager* pAM)
{
	char* temp1 = (char*)malloc(sizeof(char));
	char* temp2 = (char*)malloc(sizeof(char));
	pF->seatCost = 0;
	float cost = 0;

	while(cost < 0)
	{
		printf("Enter an seat cost: \n");
		scanf("%.2f", &cost);
	}

	printf("Enter source port code: \n");
	initCode(temp1);

	printf("Enter destination port code: \n");
	initCode(temp2);

	while (findPortByCode(pAM, temp1)|| findPortByCode(pAM, temp2))
	{

		if (findPortByCode(pAM, temp1))
		{
			initCode(temp1);
			printf("This source code already used --> Choose different one");
		}

		if (findPortByCode(pAM, temp2))
		{
			initCode(temp2);
			printf("This destination code already used --> Choose different one");
		}
	}
	strcmp(pF->sourceIATA, temp1);
	strcmp(pF->destIATA, temp2);

	Date* tempDate = (Date*)malloc(sizeof(Date));
	if (!tempDate)
		return 0;
	if (!(scanAndCheckDate(tempDate)))
		return 0; //date not valid!

	pF->date = tempDate;
	pF->seatCost = cost;

	return 1;
}

void printFlight(Flight* pF)
{
	printf("Flight from %s ,to %s , in date: ", pF->sourceIATA, pF->destIATA);
	printDate(pF->date);
	printf(" , standard seat cost: %.2f\n", pF->seatCost);
}

void freeFlight(Flight* pF)
{
	free(pF->date);
	free(pF);

}
