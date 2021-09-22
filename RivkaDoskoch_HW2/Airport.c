#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airport.h"

int isSameAirport(const Airport * pA1, const Airport * pA2)
{
	const Airport* Air1 = (const Airport*)pA1;
	const Airport* Air2 = (const Airport*)pA2;
	if (strcmp(pA1->IATA, pA2->IATA))
		return 1;
	
	
	return 0;
}

int isSameCode(const Airport * pA, const char * IATA)
{
	if (!strcmp(pA->IATA, IATA))
		return 1;

	return 0;
}

void initAirport(Airport* pA)
{
	pA->name = getStrExactName("Enter airport name");

	pA->country = getStrExactName("Enter airport country");

}

void initCode(char* IATA)
{
	char temp[MAXSTRLEN];
	int enter = 1;
	while (enter)
	{
		printf("Enter IATA code with %d upper case letters: ", CODELEN);
		myGets(temp, MAXSTRLEN);

		if (strlen(temp) != CODELEN)
			printf("\nthe code is too short, try again.\n");

		else
		{
			for (int i = 0; i < CODELEN; i++)
			{
				if (isupper(temp[i]) == 0)
				{
					printf("\nenter upper case all letters --> try again.\n");
					break;
				}

				enter = 0;
			}
		}
			
	}
	strcpy(IATA, temp);
}

void printAirport(Airport * pA)
{
	printf("Airport: %s\t, from %s\t, IATA code: %s\n", pA->name, pA->country, pA->IATA);

}

void freeAirport(Airport* pA)
{
	free(pA->country);
	free(pA->name);
}




