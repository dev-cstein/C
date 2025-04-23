//Calvin Steinbach - Array 3, inhalt.c

#include <stdio.h>

int main (void)
{
	int zahl;
	int i;

	printf("Bitte Zahl eingeben: \n");
	scanf("%i", &zahl);

	for (i = 0; zahl > 0; i++)
	{
			zahl = zahl % 10;
			printf("%i", zahl);
			zahl = zahl /10;
			printf("%i", zahl);
	}
}
