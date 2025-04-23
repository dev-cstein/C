//Calvin Steinbach - Übung Arrays, Aufgabe1 und Aufgabe2

#include <stdio.h>

int main (void)
{
	int array1[] = {2,17,10,9, 16, 3, 9, 16, 5, 1, 17, 14};
	int array2[12];
	int array3[12] = {0};
	int i;
	int sum = 0;

	for (i = 0; i < 12; i++)
	{
		sum = sum + array1[i];
		printf("%i\n", sum);
	}

	printf("-----------\n");
	
	for (i = 0; i < 12; i++)
	{
		array2[i] = array1[i] + 10;
		printf("%i\n", array2[i]);
	}
	
	return 0;
	
	for (i = 0; i < 12; i++)
	{
		if (array[i] > 10)
		{	
			
		}
	}


}
