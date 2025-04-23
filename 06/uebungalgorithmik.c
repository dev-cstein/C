//Calvin Steinbach - Übung Algorithmik


#include <stdio.h>

int main(void)
{
	int zahl1;
	int zahl2;
	int ergebnis = 0;
	int zaehler = 0;

	printf("Gib Zahl 1 ein: \n");
	scanf(" %i", &zahl1);
	printf("Gib Zahl 2 ein: \n");
	scanf(" %i", &zahl2);

	while(zaehler < zahl1)
	{
		zaehler++;
		ergebnis = ergebnis + zahl2;
	}
	printf("%i * %i = %i\n", zahl1, zahl2, ergebnis);
	return  0;
}
