//Calvin Steinbach - Taschenrechner.c

#include <stdio.h>

int main(void)
{
	float zahl1;
	float zahl2;
	float ergebnis;
	char operator;

	printf("TASCHENRECHNER:\n");
	printf("---------------\n");
	printf("Zahl 1 eingeben:\n");
	scanf(" %f", &zahl1);
	printf("Wähle einen Operator: (+ - * /)\n");
	scanf(" %c", &operator);
	printf("Zahl 2 eingeben:\n");
	scanf(" %f", &zahl2);

	switch(operator)
	{
		case '+':
		ergebnis = zahl1 + zahl2;
		printf("%.2f + %.2f = %.2f\n", zahl1, zahl2, ergebnis);
		break;
		case '-':
		ergebnis = zahl1 - zahl2;
		printf("%.2f - %.2f = %.2f\n", zahl1, zahl2, ergebnis);
		break;
		case '*':
		ergebnis = zahl1 * zahl2;
		printf("%.2f * %.2f = %.2f\n", zahl1, zahl2, ergebnis);
		break;
		case '/':
		if (zahl1 == 0 || zahl2 == 0)
		{
			printf("Division durch 0 nicht möglich\n");
		}
		else 
		{
			ergebnis = zahl1 / zahl2;
			printf("%.2f / %.2f = %.2f", zahl1, zahl2, ergebnis);
		}
		break;
	}			



}
