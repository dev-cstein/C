//Calvin Steinbach - VonNullbis99.c

#include <stdio.h>

int main(void)
{
	int zahl;
	int zaehler1;
	int zaehler2; 

	printf("Bitte Zahl eingeben: ");
	scanf("%i", &zahl); 
	
	for (zaehler1 = 1; zaehler1 <= zahl; zaehler1++)
	{
		
		for (zaehler2 = 0; zaehler2 <= zahl; zaehler2++)
		{
			printf("%i\n", zaehler2);
		}
		printf("%i\n", zaehler1);	
	}
	
	return 0;
}
