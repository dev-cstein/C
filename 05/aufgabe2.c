//Calvin Steinbach - Negative Zahl, Aufgabe2

#include <stdio.h>

int main(void)
{
	int zahl;

	printf("NEGATIV oder POSITIV\n");
	printf("--------------------\n");
	printf("Gib eine Zahl ein:\n");
	scanf("%i", &zahl);
	if (zahl < 0)
	{
		printf("Die Zahl %i ist negativ\n", zahl);
	}
	else
	{
		printf("Die Zahl %i ist positiv\n", zahl);
	}
	return 0;
}	
