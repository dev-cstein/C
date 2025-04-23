//Calvin Steinbach - Mehrdimensionale Arrays, einmaleinsmatrix.c

#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int matrix[9][9] = {0};

	for(i = 0; i < 9; i++) //Befüllen der Matrix
	{
		for(j = 0; j < 9; j++)
		{
			matrix[i][j] = (i+1) * (j+1);
		}
	}
	
	for(i = 0; i < 9; i++) //Ausgabe Mehrdimensionales Array
	{
		for(j = 0; j < 9; j++)
		{
			printf("%4i", matrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
