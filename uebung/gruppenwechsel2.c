#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "split.h"

void dateiVerarbeiten(void);

int main(void)
{
	
	dateiVerarbeiten();

	return 0;
}

void dateiVerarbeiten(void)
{	
	FILE *input;
	char *eof;
	char temp[255];
	char knr[255];
	
	int aktuelleKundennummer; 
	int letzteKundennummer;
	int position;
	float einzelbetrag;
	float gesamtumsatz;

	char datum[255];
	char betrag[255];
	
	input = fopen("bestellungen.csv", "r");
	
	if(input == NULL)
	{
		printf("Fehler! Datei konnte nicht geöffnet werden.");
	}
	else
	{
		eof = fgets(temp, 255, input);
		
		

		while(eof != NULL)
		{
			position = split(temp, knr, ';');
			aktuelleKundennummmer = atoi(knr);
			letzteKundennummer = aktuelleKundennummer;
			gesamtumsatz = 0;


			while(eof != NULL && aktuelleKundennummer == letzteKundennummer)
			{
				position += split(temp + position, datum, ';');
				position += split(temp + position, betrag, ';');
				
				einzelbetrag = atof(betrag);
				gesamtumsatz += einzelbetrag;
				
				printf("",);
				
				eof = fgets(temp, 255, input); 
			}


		}
		fclose(input);
	}
}

