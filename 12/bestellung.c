//Dateiverarbeitung - bestellung.c 

#include <stdio.h>

int main(void)
{
	FILE *fp;
	int artikelnummer = 0;
	int menge = 0;
	float gesamtpreis = 0;
	float preis_bestellung = 0;
	float betrag = 0; 

	fp = fopen("bestellung.csv", "r");

	if(fp == NULL)
	{
		printf("Datei konnte nicht geöffnet werden!");
	}
	else
	{	
		printf("ANR\tMenge\tPreis\tGesamtpreis\n");

		while(fscanf(fp, "%i;%i;%f", &artikelnummer, &menge, &betrag) == 3)
		{
			gesamtpreis = menge * betrag;
			preis_bestellung += gesamtpreis; 

			printf("%i\t%i\t%.2f\t%.2f\n", artikelnummer, menge, betrag, gesamtpreis);					
		}

		printf("Die Bestellung kostet insgesamt %.2f€.\n", preis_bestellung); 
	}
	return 0;
}
