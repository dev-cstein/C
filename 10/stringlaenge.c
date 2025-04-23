//Calvin Steinbach - Stringfunktionen, String Länge.c

#include <stdio.h>
#include <string.h>

int main(void)
{
	char test[] = {"Wie lang ist der String?"};
	int laenge;

	laenge = strlen(test);
	printf("%i\n", laenge); 

	return 0; 
}
