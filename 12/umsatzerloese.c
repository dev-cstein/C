//Calvin Steinbach - Dateiverarbeitung, umsatzerloese.c

#include <stdio.h>

int main(void)
{
	FILE *fp;
	float mitarbeiter_umsatz;
	float summe = 0;

	fp = fopen("Umsatz.csv", "r");

	if(fp == NULL)
	{
		printf("Fehler, Datei konnte nicht geöffnet werden!\n");
	}
	else
	{
		while(fscanf(fp, "%f", &mitarbeiter_umsatz) != EOF)
		{
			summe = summe + mitarbeiter_umsatz;
			printf("%.2f\n", mitarbeiter_umsatz); 
		}

		printf("Die Summe beträgt %.2f€\n", summe); 
	}
	return 0; 
}
