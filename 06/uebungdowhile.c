//Calvin Steinbach - Übung Do-While Schleife

#include <stdio.h>

int main(void)
{

	int auswahl;
	
	do
	{
		printf("1) Einfacher Taschenrechner\n");
		printf("2) Wissenschaftlicher Taschenrechner\n");
		printf("3) Informatischer Taschenrechner\n");
		printf("4) Beenden\n");
		printf("Programmwahl:\n");
		scanf(" %i", &auswahl);
		printf("**************************************\n");
	
		switch(auswahl)
		{
			case 1:
			printf("1) Einfacher Taschenrechner\n");
			printf("**************************************\n");
			break;
			case 2:
			printf("2) Wissenschaftlicher Taschenrechner\n");
			printf("**************************************\n");
			break;
			case 3:
			printf("3) Informatischer Taschenrechner\n");
			printf("**************************************\n");
			break;
			case 4:
			printf("4) Beenden\n");
			printf("**************************************\n");
			break;

		}
	}while (auswahl < 4);
	
	return 0;
}
