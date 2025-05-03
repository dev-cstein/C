//Pointer - Potenz einer Zahl

#include <stdio.h>

void potenz(int *basis, int *exponent, int *ergebnis);

int main(void)
{
	int basis;
	int exponent;
	int ergebnis = 1;

	potenz(&basis, &exponent, &ergebnis); 

	printf("Ergebnis: %i\n", ergebnis); 

	return 0;
}

void potenz(int *basis, int *exponent, int *ergebnis)
{
	int i;

	printf("Gib die Basis ein:\n");
	scanf("%i", basis);

	printf("Gib den Exponenten ein:\n");
	scanf("%i", exponent); 
	
	for(i = 0; i <= *exponent; i++)
	{
		*ergebnis *= *basis;
	}

}
