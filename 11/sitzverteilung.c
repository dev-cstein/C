//Calvin Steinbach - Mehrdimensionale Arrays, sitzplatzverteilung.c

#include <stdio.h>

void array_befuellen(char kinositze[][20]);
void ausgabe_kinositze(char kinositze[][20]);
void auswahl_kinositze(char kinositze[][20]); 

int main(void)
{
	int i;
	int j;
	char kinositze[15][20];
	
	array_befuellen(kinositze);
	ausgabe_kinositze(kinositze);
	auswahl_kinositze(kinositze);

	return 0;
}

void array_befuellen(char kinositze[][20])
{
	int i;
	int j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 20; j++)
		{
			kinositze[i][j] = 'o'; 
		}
	}

}

void ausgabe_kinositze(char kinositze[][20])
{
	int i;
	int j;

	printf("Sitz:     "); 

	for(i = 1; i < 21; i ++)
	{
		if (i < 10)
		{
			printf("%i  ", i);
		}
		else
		{
			printf("%i ", i);

		}
	}
	
	printf("\n\n");

	for(i = 1; i < 15; i++) //Zeile
	{
		if (i < 10)
		{
			printf("Reihe %i  ", i);
		}
		else
		{
			printf("Reihe %i ", i); 
		}

		for(j = 0; j < 20; j++) //Spalte
		{
			printf(" %c ", kinositze[i][j]);
		}
		printf("\n");
	}
}

void auswahl_kinositze(char kinositze[][20])
{
	int reihe;
	int sitz;
	int auswahl;

	printf("\n");

	do
	{
		printf("Welche Reihe möchten Sie buchen?\n");
		scanf("%i", &reihe);

		printf("Welchen Sitz möchten Sie buchen?\n");
		scanf("%i", &sitz);		

		kinositze[reihe][sitz - 1] = 'x'; 

		ausgabe_kinositze(kinositze);

		printf("Möchten Sie weitere Plätze buchen? (1 = Ja 0 = Nein)\n");
		scanf("%i", &auswahl); 
	
	} while(auswahl);

	
}




