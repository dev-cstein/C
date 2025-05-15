#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

void verarbeitung(FILE *);
void ausgabekopf(int, FILE *);
void ausgabekoerper(char *, float, FILE *);
void ausgabefuss(float, FILE *);

int main(void)
{
	FILE *input;

	verarbeitung(input);

	return 0;
}
void verarbeitung(FILE *input)
{
	FILE *output;
	char *eof;
	char temp[255];
	char knr[255], datum[255], einzelpreis[255];
	char dateiformat[5] = ".txt";

	int laenge = 0;
	int kunde, kundennummer;
	float preis, gesamtumsatz;

	input = fopen("bestellungen.csv","r");

	if(input == NULL)
	{
		printf("Fehler beim öffnen der Datei!");
	}
	else
	{
		eof = fgets(temp, 255, input);

		while(eof != NULL)
		{
			laenge = split(temp, knr, ';');
			kunde = atoi(knr);
			kundennummer = kunde;
			gesamtumsatz = 0;
			strcat(knr, dateiformat);
			output = fopen(knr, "w");
			ausgabekopf(kunde, output);

			while(eof != NULL && kunde == kundennummer)
			{
				laenge += split(temp + laenge, datum, ';');
				laenge += split(temp + laenge, einzelpreis, ';');
				kunde = atoi(knr);
				preis = atof(einzelpreis);
				gesamtumsatz += preis;

				ausgabekoerper(datum, preis, output);

				eof = fgets(temp, 255, input); 
				laenge = split(temp, knr, ';');
				kundennummer = atoi(knr);
			}

			ausgabefuss(gesamtumsatz, output);
			fclose(output);
		}
		fclose(input);
	}
}

void ausgabefuss(float gesamtumsatz, FILE *output)
{
	printf("-----------------------------------------------------------\n");
	printf("Der Gesamtumsatz beträgt %6.2f\n\n", gesamtumsatz);

	fprintf(output, "-----------------------------------------------------------\n");
	fprintf(output, "Der Gesamtumsatz beträgt: %6.2f\n\n", gesamtumsatz);
}

void ausgabekoerper(char *datum, float preis, FILE *output)
{
	printf("%s %12.2f €\n", datum, preis);

	fprintf(output, "%s %12.2f €\n", datum, preis);
}
void ausgabekopf(int kunde, FILE *output)
{
	printf("Bestellung des Kunden: %i\n", kunde);
	printf("Datum\t\t Preis\n");

	fprintf(output, "Bestellung des Kunden: %i\n", kunde);
	fprintf(output, "Datum\t\t Preis\n");
}
