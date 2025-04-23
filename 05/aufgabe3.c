//Calvin Steinbach - Aufgabe 2, Negative Zahl

#include <stdio.h>

int main(void)
{
	int zahl;

	printf("GERADE oder UNGERADE\n");
	printf("--------------------\n");
	printf("Bitte Zahl eingeben: ");
	scanf("%i", &zahl);
	
	if (zahl % 2 == 0)
	{
		printf("Die Zahl %i ist gerade!\n", zahl);
	}
	else
	{
		printf("Die Zahl %i ist ungerade!\n", zahl);
	}
	return 0;
}
