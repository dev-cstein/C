//Calvin Steinbach - Zahlenreihe.c

#include <stdio.h>

int main(void)
{
	int zahl1;
	int zahl2;
	int zaehler;
	int ergebnis;

	printf("Bitte Anfangszahl eingeben: ");
	scanf("%i", &zahl1); 

	printf("Bitte Endzahl eingeben: ");
	scanf("%i", &zahl2);

	for (zaehler = 0; zaehler > zahl1 && zaehler < zahl2; zaehler++)
	{
		printf("%i", zaehler); 
	}
}
