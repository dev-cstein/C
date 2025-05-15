#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

void verarbeiten(FILE *input);
void ausgabekorper(char *datum, char *preis, FILE *output);

int main(void)
{
	FILE *input;
	
	verarbeiten(input);

	return 0;
}

void verarbeiten(FILE *input)
{
	FILE *output;

	char *eof;
	char temp[100];
	char knr[25], datum[20], preis[20];
	char dateiformat[5] = ".txt";

	int laenge = 0;
	int kundennummer;
	int kunde;

	float einzelpreis;
	float gesamtumsatz = 0;

	input = fopen("bestellungen.csv", "r");
	if(input == NULL)
	{	
		printf("Datei konnte nicht geöffnet werden.\n");
	}
	else
	{
		eof = fgets(temp, 100, input);

		while(eof != NULL)
		{
			laenge = split(temp, knr, ';');
			kunde = atoi(knr);
			kundennummer = kunde;
			gesamtumsatz = 0;

			strcat(knr, dateiformat);
			output = fopen(knr, "w");

			ausgabekopf(kunde, output);

			while(eof != NULL && kundennummer == kunde)
			{
				laenge += split(temp + laenge, datum, ';');
				laenge += split(temp + laenge, preis, ';');
				einzelpreis = atof(preis);
				gesamtumsatz += einzelpreis;
				
				ausgabekoerper(datum, preis, output);

				eof = fgets(temp, 100, input);
				laenge = split(temp, knr, ';');
				kunde = atoi(knr);

			}
			ausgabefuss(gesamtumsatz, output);
			fclose(output);
		}
		fclose(input);
	}

}
