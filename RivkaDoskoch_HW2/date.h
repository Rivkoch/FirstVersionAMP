#pragma once

#define MINYEAR 2021

typedef struct
{
	int		day;
	int		month;
	int		year;
}Date;

int		scanAndCheckDate(Date* pDate);
void	printDate(Date * pDate);

