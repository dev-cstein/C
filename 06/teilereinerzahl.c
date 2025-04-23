//Calvin Steinbach - Teiler einer Zahl

#include <stdio.h>

int main(void)
{
	int zahl;
	int zaehler;
	int ergebnis;
	
	printf("Bitte geben Sie die Zahl ein, für die Sie die Teiler wissen möchten: ");
	scanf("%i", &zahl);

	for (zaehler = 1; zaehler <= zahl; zaehler++)
	{
		if (zahl % zaehler == 0)
		{
			ergebnis = zahl / zaehler;
			printf("%i\n", ergebnis); 
		}
	}
	return 0; 
}
