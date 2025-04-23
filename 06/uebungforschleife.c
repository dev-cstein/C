// Calvin Steinbach - Übung For-Schleife

#include <stdio.h>

int main(void)
{
	int durchlaeufe;
	int zaehler;
	
	printf("Bitte Anzahl der Durchläufe eingeben: ");
	scanf("%i", &durchlaeufe);
	
	for (zaehler = 1; zaehler <= durchlaeufe; zaehler++)
	{
		printf("Dies ist der %i Durchlauf.\n", zaehler);
	}
	return 0;
}
