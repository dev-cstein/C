//Calvin Steinbach - Uebernachtungspreis.c

#include <stdio.h>

int main(void)
{
	int einzelZimmer = 60;
	int doppelZimmer = 80;
	int fruehstueck = 10;
	int anzahlNaechte;
	int zimmerAuswahl;
	int fruehstueckAuswahl;
	int zimmerpreis;


	printf("Willkomen im Hotel\n");
	printf("------------------\n");
	printf("Einzelzimmer (1) oder Doppelzimmer (2) wählen:\n");
	scanf(" %i", &zimmerAuswahl);
	printf("Wie viele Nächte wollen sie bleiben?\n");
	scanf(" %i", &anzahlNaechte);
	printf("Wünschen Sie Frühstück ja(1) oder nein(0)\n");
	scanf(" %i", &fruehstueckAuswahl);

	if (zimmerAuswahl == 1 && fruehstueckAuswahl == 0)
	{
		zimmerpreis = einzelZimmer * anzahlNaechte;
		printf("Der Preis beträgt %i Euro.\n", zimmerpreis);
	}
	else if (zimmerAuswahl == 1 && fruehstueckAuswahl == 1)
	{
		zimmerpreis = (einzelZimmer + fruehstueck) * anzahlNaechte;
		printf("Der Preis beträgt %i Euro.\n", zimmerpreis);
	}
	else if (zimmerAuswahl == 2 && fruehstueckAuswahl == 0)
	{
		zimmerpreis = doppelZimmer * anzahlNaechte;
		printf("Der Preis beträgt %i Euro.\n", zimmerpreis);
	}
	else if (zimmerAuswahl == 2 && fruehstueckAuswahl == 1)
	{
		zimmerpreis = (doppelZimmer + fruehstueck) * anzahlNaechte;
		printf("Der Preis beträgt %i Euro.\n", zimmerpreis);
	}
	return 0;
}
