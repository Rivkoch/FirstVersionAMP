#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Airline.h"
#include "AirportManager.h"
#include "General.h"


int main() 
{
	AirportManager pAirportManager;
	Airline pAirline;

	if (!(initAirportManager(&pAirportManager)))
	{
		printf("Initialization not work. Can't insert airports\n");
		return 0;
	}

	if (!(initAirline(&pAirline)))
	{
		printf("Initialization not work. Can't insert airline\n");
		return 0;
	}

	int choose = 0;
	int toContinue = 1;
	fflush(stdin);

	do
	{
		printf("\nChoose one of the following options :\n");
		printf("1 - Add Flight\n");
		printf("2 - Add airport\n");
		printf("3 - Print Airline\n");
		printf("4 - Print All Airports\n");
		printf("5 - Print flights between sourse and destination ports\n");
		printf("6 - Quit\n");
		fflush(stdin);
		scanf("%d", &choose);
		printf("\n");


		switch (choose)
		{
		case 1:
		{   
			getchar();
			addFlight(&pAirline, &pAirportManager);
			break;
		}
		case 2: 
		{
			getchar();
			addAirport(&pAirportManager);
			break;
		}
		case 3: 
		{
			printAirline(&pAirline);
			break;
		}
		case 4: 
		{
			printAirportManager(&pAirportManager);
			break;
		}
		case 5:
		{
			printf("The airline have %d flights in this line. \n", howManyFlightsInLine(&pAirline));
			break;
		}

		case 6://needs to free all the memory
		{
			printf("Bye Bye");

			freeAirline(&pAirline);
			freeAirportManager(&pAirportManager);
			toContinue = 0;
			break;
		}

		}

		printf("\n");

	} while (toContinue);


	return 1;
}
