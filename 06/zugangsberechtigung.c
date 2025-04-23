//Calvin Steinbach - zugangsberechtigung.c

#include <stdio.h>

int main(void)
{
	int anzahlPersonen;
	int person = 1;
	int zaehler = 1;
	int alter;
	int u18 = 0;
	int ue18 = 0;


	printf("Bitte geben Sie die Anzahl der Personen an:\n");
	scanf(" %i", &anzahlPersonen);

	while(zaehler <= anzahlPersonen)
	{
		zaehler++;
		printf("Bitte geben Sie das Alter der %i. Person an\n", person);
		scanf(" %i", &alter);
		person++;
		if(alter <18)
		{
			u18++;		
		}
		else
		{
			ue18++;
		}
	}
	printf("%i Person(en) dürfen eintreten, der Rest von %i Person(en) muss draußen bleiben.\n", ue18, u18);
	return 0;
}
