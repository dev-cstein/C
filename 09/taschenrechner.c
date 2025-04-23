//Calvin Steinbach - Funktionen, taschenrechner.c

#include <stdio.h>

float addiere(float zahl1, float zahl2);
float subtrahiere(float zahl1, float zahl2);
float multipliziere(float zahl1, float zahl2);
float dividiere(float zahl1, float zahl2); 

int main(void)
{
	char operator;
	float zahl1;
	float zahl2;
	float ergebnis;

	printf("+------------------------+\n");
	printf("|			 |\n");
	printf("|     Taschenrechner     |\n");
	printf("|			 |\n");
	printf("+------------------------+\n");
	printf("\n");

	printf("Bitte gib die Rechenoperation (+ - * /) an:");
	scanf("%c", &operator);

	printf("Bitte gib die erste Zahl ein:");
	scanf("%f", &zahl1); 

	printf("Bitte gib die zweite Zahl ein:");
	scanf("%f", &zahl2);

	switch(operator)
	{
		case '+':
		ergebnis = addiere(zahl1, zahl2);
		printf("%g + %g = %g\n", zahl1, zahl2, ergebnis);
		break;

		case '-':
		ergebnis = subtrahiere(zahl1, zahl2);
		printf("%g - %g = %g\n", zahl1, zahl2, ergebnis);
		break;

		case '*':
		ergebnis = multipliziere(zahl1, zahl2);
		printf("%g * %g = %g\n", zahl1, zahl2, ergebnis);
		break;

		case '/':
		ergebnis = dividiere(zahl1, zahl2); 
		printf("%g / %g = %g\n", zahl1, zahl2, ergebnis);
		break;
	
	}
	return 0;
}	

float addiere(float zahl1, float zahl2)
{
	return zahl1 + zahl2;
}
float subtrahiere(float zahl1, float zahl2)
{
	return zahl1 - zahl2; 
}
float dividiere(float zahl1, float zahl2)
{
	return zahl1 / zahl2; 
}
float multipliziere(float zahl1, float zahl2)
{
	return zahl1 * zahl2; 
}


