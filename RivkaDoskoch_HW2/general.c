#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "general.h"

char* getStrExactName(const char* msg)
{
	char* str;
	char temp[MAXSTRLEN];
	printf("%s\t", msg);
	myGets(temp, MAXSTRLEN);

	str = getDynStr(temp);
	return str;
}

char* getDynStr(char* str)
{
	char* theStr;
	theStr = (char*)malloc((strlen(str) + 1) * sizeof(char));// allocate 
	if (!theStr)
		return NULL;

	strcpy(theStr, str);
	return theStr; // retern one word
}



char*  myGets(char* buffer, int size)
{
	if (buffer != NULL && size > 0)
	{
		if (fgets(buffer, size, stdin))
		{
			buffer[strcspn(buffer, "\n")] = '\0';
			return buffer;
		}
		buffer[0] = '\0';
	}
	return NULL;
}
