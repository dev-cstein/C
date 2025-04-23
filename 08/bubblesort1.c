//Calvin Steinbach - Bubblesort Algorythmus

#include <stdio.h>

int main (void)
{
	int i;
	int j;
	float temp;
	float array[10] = {9.12, 244, 12, 1, 5, 7, 20.4, 14, 11, 2};

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (array[j] > array[j +1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}	
		}
	 
	}
	for (i = 0; i < 10; i++)
	{
		printf("%g\n", array[i]); 
	}

	return 0;

}

	 
