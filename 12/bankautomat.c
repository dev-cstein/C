#include <stdio.h>
#include "split.h"

int main(void)
{
	FILE *fp;
	int kontostand;
	int sperre;
	int pin;
	int pin_eingabe;
	char benutzername_eingabe[50] = {0};
	char benutzername[50] = {0};

	fp = fopen("bankautomat.csv", "r");

	if(fp == NULL)
	{
		printf("Datei konnte nicht geöffnet werden");
	}
	else
	{
		fgets(benutzername, 50, fp);
		printf("%s", benutzername);


	}

	return 0;
}


