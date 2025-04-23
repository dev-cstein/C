//Calvin Steinbach - Funktionen, Positive Zahlen.c

#include <stdio.h>

int positive_zahl(int);

int main (void)
{
	int zahl1;
	int ergebnis;

	printf("Bitte Zahl eingeben:\n");
	scanf("%i", &zahl1);

	ergebnis = positive_zahl(zahl1);
	
	if (ergebnis > 0)
	{
		printf("Positiv\n");
	}
	else
	{
		printf("Negativ\n");
	}

	return 0;
}

int positive_zahl(int zahl1)
{
	if (zahl1 > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 0;
}
