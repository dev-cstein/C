// Calvin Steinbach - Zahlenstrahl, Aufgabe 5

#include <stdio.h>

int main(void)
{
	int zahl1;
	int zahl2;
	int zahl3;

	printf("Bitte Zahl1 eingeben:\n");
	scanf("%i", &zahl1);

	printf("Bitte Zahl2 eingeben:\n");
	scanf("%i", &zahl2);
	
	printf("Bitte Zahl3 eingeben:\n");
	scanf("%i", &zahl3);
	
	if (zahl3 > zahl1 && zahl3 < zahl2)
		printf("Die Zahl %i liegt im Bereich von %i und %i\n", zahl3, zahl1, zahl2);
	else
	{
		printf("Die Zahl %i liegt nicht im Bereich von %i und %i\n", zahl3, zahl1, zahl2);
	}

	return 0;
}
