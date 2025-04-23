//Dateiverarbeitung - Übung 2, Umsätze

#include <stdio.h>
#define MAX_FILIALEN 6

int main(void)
{
	FILE *fp;
	int betrieb_nr, i;
	float betrag;
	float filialen[MAX_FILIALEN + 1] = {0};
	
	

	fp = fopen("umsatz.csv", "r");
	
	if(fp == NULL)
	{
		printf("Datei konnte nicht geöffnet werden");
	}
	else
	{	
		while(fscanf(fp, "%d;%f", &betrieb_nr, &betrag) == 2) 
		{
			if(betrieb_nr < 1 || betrieb_nr > MAX_FILIALEN)
			{
				printf("Ungültige betrieb_nr");
				return 1;
			}
			else
			{
				filialen[betrieb_nr] += betrag;
			}
		}

		for(i = 1; i <= MAX_FILIALEN; i++)
		{
			printf("FNR %d: %.2f€\n", i, filialen[i]);
		}

		fclose(fp);
	}

	return 0;
}
