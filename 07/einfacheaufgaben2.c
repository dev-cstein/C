//Calvin Steinbach -- Einfache Aufgaben-Arrays, Aufgabe 2

#include <stdio.h>

int main (void)
{
	int array[11];
	int i;
	
	for (i = 0; i <=10; i++)
	{
		array[i] = i;
		printf("array[%i] = %i\n",i, i);
	}
	return 0;
}

