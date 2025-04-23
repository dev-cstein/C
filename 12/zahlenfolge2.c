//Calvin Steinbach - Dateiverarbeitung, zahlenfolge2.c

#include <stdio.h>

int main(void)
{
	FILE *fp;
	int temp;
	int i;

	fp = fopen("zahlenfolge.txt", "r");
	
	if(fp == NULL)
	{
		printf("Fehler beim öffnen der Datei!");  
	}
	else
	{
		for(i = 0; i < 10; i++)
		{
			fscanf(fp, "%i\n", &temp);
			printf("%i\n", temp); 
		}
	}

	fclose(fp);
}
