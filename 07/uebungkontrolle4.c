//Calvin Steinbach - Übung Kontrolle, Aufgabe 4

#include <stdio.h>

int main(void)
{
	int i;
	int testarray[10] = {1,2,3};
	int length = sizeof(testarray) / sizeof(testarray[0]);

	for (i = 0; i <= length; i++)
	{
		printf("testarray[%i] = %i\n", i, testarray[i]);
	}

	return 0;
}
