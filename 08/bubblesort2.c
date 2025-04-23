//Calvin Steinbach - Bubblesort, Aufgabe 1

#include <stdio.h>

int main(void)
{
	float array[10] = {15, 19.4, 3, 2.5, 97, 4, 84.2, 76, 65, 22.3};
	float zwischenspeicher;
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (array[j] < array[j + 1])
			{
				zwischenspeicher = array[j];
				array[j] = array[j + 1];
				array[j + 1] = zwischenspeicher; 

			}
		}
	
	}

	for (i = 0; i < 10; i++)
	{
		printf("%g\n", array[i]);
	}
	return 0; 
}

