//Calvin Steinbach - Dateiverarbeitung, gruppenwechsel.c

#include <stdlib.h>
#include <stdio.h>
#include "split.h"

void gruppenkopf();

int main(void)
{
	char zeile[100]; 
	int aktueller_kunde[100] = {0};
	char datum[20]; 
	float aktueller_betrag;
	float summe = 0;


	FILE *fp;

	fp = fopen("gruppenwechsel_sorted.txt", "r");

	if(fp == NULL)
	{
		printf("Datei konnte nicht geöffnet werden!");
		return 1;
	}
	else
	{
		if(fgets(zeile, 100 fp) != NULL)
		{
			split(zeile, aktueller_kunde, ';'); //Kundennummer extrahieren

			printf("%c", aktueller_kunde[]); 
	
	//	do
	//		{
	//	 
	// while;


		}
		 
	}
	return 0; 
}
