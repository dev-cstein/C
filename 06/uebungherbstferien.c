//Calvin Steinbach - Schere, Stein, Papier
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
	int spielerEinsAuswahl;
	int spielerZweiAuswahl;
	bool waffenAuswahlEins = false;
	bool waffenAuswahlZwei = false;
	int punktestandSpielerEins = 0;
	int punktestandSpielerZwei = 0;
	int rundenZahl = 1;

    void spielStart()
	{   
		printf("+------------------------+\n");
        printf("|                        |\n");
        printf("| Schere, Stein, Papier! |\n");
        printf("|                        |\n");
        printf("+------------------------+\n");
        printf("\n");
		
		sleep(1);
	}

	
	void waffenAuswahlSchleife()
	{
		while (waffenAuswahlEins == false || waffenAuswahlZwei == false)
		{
			//SpielerEinsAuswahl

			printf("Spieler 1: Wähle deine Waffe!\n");
			printf("Schere (1)\n");
			printf("Stein (2)\n");
			printf("Papier (3)\n");
			printf("Auswahl: ");
			scanf("%i", &spielerEinsAuswahl);
		
			if (spielerEinsAuswahl > 3 || spielerEinsAuswahl == 0)
			{
				printf("Keine Gültige Auswahl!");
			}
			else
			{
				waffenAuswahlEins = true;
			}

			printf("\n");
			printf("\n");
			
			sleep(1);

			//SpielerZweiAuswahl
			
			printf("Spieler 2: Wähle deine Waffe!\n");
			printf("Schere (1)\n");
			printf("Stein (2)\n");
			printf("Papier (3)\n");
			printf("Auswahl: ");
			scanf("%i", &spielerZweiAuswahl);

			if (spielerZweiAuswahl > 3 || spielerZweiAuswahl == 0)
			{
				printf("Keine Gültige Auswahl!");
			}
			else
			{
				waffenAuswahlZwei = true;
			}
			printf("\n");
		
		}
	}
	void spielSchleife()
	{	
		waffenAuswahlSchleife();

		while (rundenZahl <= 3)
		{
			
	      	printf("Round %i\n", rundenZahl);

			sleep(1);

        	printf("Fight!!!\n\n");

			rundenZahl++;

			sleep(1);

			if (spielerEinsAuswahl == 1 && spielerZweiAuswahl == 1)
			{
				printf("Unentschieden! Niemand bekommt einen Punkt.\n\n");
			
			}
			else if (spielerEinsAuswahl == 1 && spielerZweiAuswahl == 2)
			{
				printf("Stein schlägt Schere!\n\n");
				punktestandSpielerZwei++;
	
			}
			else if (spielerEinsAuswahl == 1 && spielerZweiAuswahl == 3)
			{
				printf("Papier schlägt Stein!\n\n");
				punktestandSpielerZwei++;
			
			}
			else if (spielerEinsAuswahl == 2 && spielerZweiAuswahl == 1)
			{
				printf("Stein schlägt Schere!\n\n");
				punktestandSpielerEins++;
	
			}
			else if (spielerEinsAuswahl == 2 && spielerZweiAuswahl == 2)
			{
				printf("Unentschieden! Niemand bekommt einen Punkt.\n\n");
	
			}
			else if (spielerEinsAuswahl == 2 && spielerZweiAuswahl == 3)
			{
				printf("Papier schlägt Stein!\n\n");
				punktestandSpielerZwei++;
			}
			else if (spielerEinsAuswahl == 3 && spielerZweiAuswahl == 1)
			{
				printf("Schere schlägt Papier!\n\n");
				punktestandSpielerZwei++;
			}
			else if (spielerEinsAuswahl == 3 && spielerZweiAuswahl == 2)
			{
				printf("Papier schlägt Stein!\n\n");
				punktestandSpielerZwei++;
			}
			else if (spielerEinsAuswahl == 3 && spielerZweiAuswahl == 3)
			{
				printf("Unentschieden! Niemand bekommt einen Punkt.\n\n");
			
			}

			waffenAuswahlEins = false;
			waffenAuswahlZwei = false;
			
			if (rundenZahl <= 3)
			{
				waffenAuswahlSchleife();
			}

		}
	}

	void gewinner()
	{
		if (punktestandSpielerEins > punktestandSpielerZwei)
		{
			printf("Spieler 1 Gewinnt!\n");
		}
		else if (punktestandSpielerEins == punktestandSpielerZwei)
		{
			printf("Unentschieden!\n");
		}
		else if (punktestandSpielerEins < punktestandSpielerZwei) 
		{
			printf("Spieler 2 Gewinnt!\n");
		}
	}

	spielStart();
	spielSchleife();
	gewinner();

	return 0;
}








