//Calvin Steinbach - Übung Kontrolle, Aufgabe 3

#include <stdio.h>

int main(void)
{
	int array[1000];
	int i;

	for (i = 0; i < 1000; i++)
	{
		array[i] = 1;
		printf("array[%i] = %i\n", i, array[i]); 
	}
	return 0;
}	
