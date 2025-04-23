//Calvin Steinbach - Kassensoftware.c

#include <stdio.h>

int main(void)
{
	int rechnungsBetrag;
	int erhaltenerBetrag;
	int rueckgeld;
	int anzahlEinCent;
	int anzahlZweiCent;
	int anzahlFuenfCent;
	int anzahlZehnCent;
	int anzahlZwanzigCent;
	int anzahlFuenfzigCent;
	int anzahlEinEuro;
	int anzahlZweiEuro;

	printf("Rechnungsbetrag: ");
	scanf("%i", &rechnungsBetrag);
	printf("Erhaltener Betrag: ");
	scanf("%i", &erhaltenerBetrag);
	rueckgeld = erhaltenerBetrag - rechnungsBetrag;
	anzahlZweiEuro = rechnungsBetrag / 200;

	printf("=========================\n");
	printf("Rückgeld: %i€\n", rueckgeld);
	printf("=========================\n");
	
	

