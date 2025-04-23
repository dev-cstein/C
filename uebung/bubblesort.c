#include <stdio.h>

int main(void)
{
	int array[5] = {12, 34, 41, 35,5};
	int i, j, temp;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5 - 1 ; j++)
		{	
			if(array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	for(i = 0; i < 5; i++)
	{
		printf("Array[%i] = %i\n", i, array[i]);  
	}

	return 0;
}
