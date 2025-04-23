//Calvin Steinbach - Zahlenvergleich, Aufgabe 4

#include <stdio.h>

int main(void)
{
	int zahl1;
	int zahl2;

	printf("KLEINER oder GROESSER\n");
	printf("---------------------\n");
	printf("Bitte Zahl1 eingeben:\n");
	scanf(" %i", &zahl1);
	printf("Bitte Zahl2 eingeben:\n");
	scanf(" %i", &zahl2);

	if (zahl1 < zahl2)
	{
		printf("Die Zahl %i ist kleiner als Zahl %i\n", zahl1, zahl2);
	}
	else
	{
		printf("Die Zahl %i ist groesser als Zahl %i\n", zahl1, zahl2);
	}
	return 0; 
}


