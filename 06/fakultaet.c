//Calvin Steinbach - Fakultät

#include <stdio.h>

int main(void)
{
	int zahl;
	int zaehler;
	int ergebnis = 1;

	printf("Zahl eingeben:");
	scanf("%i", &zahl);

	for (zaehler = 1; zaehler <= zahl; zaehler++)
	{
		 ergebnis *= zaehler;
	}

	printf("%i! = %i\n", zahl, ergebnis);
	
	return 0; 
}
