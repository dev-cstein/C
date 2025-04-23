// Calvin Steinbach -- Übung

#include <stdio.h>

int main(void)
{
	int zaehler;
	int array[5];
	

	for (zaehler = 0; zaehler < 5; zaehler++)
		{
		array[zaehler] = zaehler;
		printf("array[%d] = %d\n",zaehler, array[zaehler]);
		}
	return 0;
}
