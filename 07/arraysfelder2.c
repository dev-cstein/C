//Calvin Steinach -- Arrays-Felder, Minimum Maximum

#include <stdio.h>

int main (void)
{
	int array[1000] = 0;
	int anzahl_zahlen;
	int i;

	printf("Bitte geben Sie ein, wie viele Zahlen Sie einlesen möchten: \n");
	scanf("%i", &anzahl_zahlen);

	for (i = 0; i <= anzahl_zahlen; i++)
	{
		printf("Bitte %i. Zahl eingeben: \n", i);
		scanf(" %i", &array[i]);
		
	}

	return 0;
}
