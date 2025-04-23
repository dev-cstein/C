//Übung Funktionen

#include <stdio.h>

int addiere(int, int);
void hallo(void);

int main(void)
{
	int zahl1;
	int zahl2;
	int summe;

	printf("Zahl 1 eingeben:\n");
	scanf("%i", &zahl1);

	printf("Zahl 2 eingeben:\n");
	scanf("%i", &zahl2);

	summe = addiere(zahl1, zahl2);
	 

	printf("%i + %i = %i\n", zahl1, zahl2, summe);
	hallo();
	
	return 0;
}

int addiere(int zahl1, int zahl2)
{
	return zahl1 + zahl2;

}
void hallo(void)
{
	printf("Hallo Welt\n");

}
