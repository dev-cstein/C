//Calvin Steinbach -- getränkeautomat.c

#include <stdio.h>

int main(void)
{
	float wasser = 0.50;
	float limo = 1.00;
	float saft = 2.00;
	float bier = 2.50;
	float geldGegeben;
	float rueckgeld;
	int auswahl;

	printf("GETRÄNKEAUTOMAT:\n");
	printf("----------------\n");
	printf("Wählen Sie ein Getränk aus:\n");
	printf("1) Wasser\n");
	printf("2) Limo\n");
	printf("3) Saft\n");
	printf("4) Bier\n");
	scanf(" %i", &auswahl);
	
	switch(auswahl)
	{
		case 1:
		printf("Der Preis für ihre Auswahl beträgt %.2f€\n", wasser);
		printf("Bitte %.2f€ einwerfen:\n", wasser);
		scanf("%f", &geldGegeben);
		rueckgeld = geldGegeben - wasser;

		if (geldGegeben >= wasser)
		{
			printf("Bitte Getränk und %.2f€ Rückgeld entnehmen\n", rueckgeld);
		}
		else
		{
			printf("Bitte verbleibenden Betrag einwerfen\n");
		}
		break;
		
		case 2:
		printf("Der Preis für Ihre Auswahl beträgt %.2f€\n", limo);
		printf("Bitte %.2f€ einwerfen:\n", limo);
		scanf("%f", &geldGegeben);
		rueckgeld = geldGegeben - limo;

		if (geldGegeben >= limo)
		{
			printf("Bitte Getränk und %.2f€ Rückgeld entnehmen\n", rueckgeld);
		}
		else
		{
			printf("Bitte verbleibenden Betrag einwerfen\n");
		}
		break;
		
		case 3:
		printf("Der Preis für ihre Auswahl beträgt %.2f€\n", saft);
		printf("Bitte %.2f€ einwerfen:\n", saft);
		scanf("%f", &geldGegeben);
		rueckgeld = geldGegeben - saft;

		if (geldGegeben >= saft)
		{
			printf("Bitte Getränk und %.2f€ Rückgeld entnehmen\n", rueckgeld);
		}
		else
		{
			printf("Bitte verbleibenden Betrag einwerfen\n");
		}
		break;

		case 4:
		printf("Der Preis für ihre Auswahl beträgt %.2f€\n", bier);
		printf("Bitte %.2f€ einwerfen:\n", bier);
		scanf("%f", &geldGegeben);
		rueckgeld = geldGegeben - bier;
		if (geldGegeben >= bier)
		{
			printf("Bitte Getränk und %.2f€ Rückgeld entnehmen\n", rueckgeld);
		}
		else
		{
			printf("Bitte verbleibenden Betrag einwerfen\n");
		}
		break;
		
		default:
		printf("Ungültige Eingabe!\n");
	}
	return 0;
}
