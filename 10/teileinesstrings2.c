//Calvin Steinbach, Strings - Teil eines Strings 2.c

#include <stdio.h>

int main(void)
{
	char string[100] = {""};
	int start;
	int ende;
	int i = 0;

	printf("Gib ein Wort ein:\n");
	scanf("%s", string);

	printf("Gib den Startpunkt ein:\n");
	scanf("%i", &start);

	printf("Gib den Endpunkt an:\n");
	scanf("%i", &ende);

	for(i = start; i < ende; i++)
	{
		printf("%c", string[i]);
	}
	
	printf("\n");

	return 0; 

}
