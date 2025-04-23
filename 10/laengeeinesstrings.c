//Calvin Steinbach - String, laengeeinesstring.c

#include <stdio.h>

int main(void)
{
	char wort[100];
	int i;

	printf("\nBitte gib ein Wort ein:\n");
	scanf("%s", wort);

	for(i = 0; wort[i] != '\0';  i++);
	
	printf("Das Wort ist %i Zeichen lang.\n", i);
		
	return 0;
}
