//Calvin Steinbach - Strings, Teil eines Strings.c

#include <stdio.h>

int main(void)
{
	char string[100] = {""};
	int laenge;
	int i;

	printf("Gib ein Wort ein:\n");
	scanf("%s", string);

	printf("Wieviele Zeichen sollen augegeben werden?\n");
	scanf("%i", &laenge);

	for(i = 0; i < laenge; i++)
	{
		printf("%c", string[i]);
	}
	printf("\n");
}
