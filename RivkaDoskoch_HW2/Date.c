#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "date.h"


int scanAndCheckDate(Date* pDate)
{
	int day, month, year;

	printf("Enter date (dd-mm-yyyy format): ");
	scanf("%d/%d/%d", &day, &month, &year);

	//check year
	if (year >= MINYEAR)
	{
		//check month
		if (month >= 1 && month <= 12)
		{
			//check days
			if ((day < 1 && day > 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
			{
				printf("Date is not valid.\n");
				return 0;
			}
			else if ((day < 1 && day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))
			{
				printf("Date is not  valid.\n");
				return 0;
			}
			else if ((day < 1 && day > 28) && (month == 2))
			{
				printf("Date is not valid.\n");
				return 0;
			}
		}
		else
		{
			printf("Month is not valid.\n");
			return 0;
		}
	}
	else
	{
		printf("Year is not valid.\n");
		return 0;
	}

	pDate->day = day;
	pDate->month = month;
	pDate->year = year;

	return 1;
}

void printDate(Date * pDate)
{
	if (pDate->day < 10)
	{
		printf("0%d-", pDate->day);
	}
	if (pDate->month < 10)
		printf("0%d-", pDate->month);
	printf("%d", pDate->year);
}


