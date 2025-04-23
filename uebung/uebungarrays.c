//Übung Arrays
#include <stdio.h>

int main(void)
{
	int array[5]= {};
	int i;

	for(i = 1; i <= 5; i++)
	{
		printf("Durchschnitt: Zahl %i eingeben:", i);
		scanf("%i", &array[i]);
	}

	return 0;
}
