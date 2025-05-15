#include <stdio.h>
#include <string.h>
#include "split.h"

struct pegelstand
{
	float hoehe;
	char stadt[255];
};

void dateiEinlesen(FILE *input);

int main(void)
{
	FILE *input;
	
	dateiEinlesen(input);
	 
	return 0;
}

void dateiEinlesen(FILE *input)
{
	char temp[255];
	char *eof;
	char feld1[255];
	char feld2[255];

	float pegel;
	char stadt[255];
	int position;

	input = fopen("pegel.csv","r");

	if(input == NULL)
	{
		printf("Fehler, Datei konnte nicht geöffnet werden!\n");
	}
	else
	{	
		eof = fgets(temp, 255, input);
		position = split(temp, feld1, ';');
		position += split(temp + position, feld2, ';');
		pegel = atof(feld1);
		stadt = feld2;
		
		while(eof != NULL && feld1 == stadt)
		{
			position += split(temp + position, feld1, ';');
			position += split(temp + position, feld2, ';');
			printf("%f, %c", pegel, stadt);

		}	

	}
}

	
	




	

