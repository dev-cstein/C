#include <stdio.h>

int main (void)
{
	float array[100];
	int i;
	int size_of_array = sizeof(array) / sizeof(array[0]);

	for (i = 0; i <= size_of_array; i++)
	{
		array[i] = 2.12;
		printf("%.2f\n", array[i]);
	}
}
