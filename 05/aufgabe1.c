//Calvin Steinbach - Aufgabe1

#include <stdio.h>
int main(void)
{
	float x;
	
	printf("Gib die Zahl ein: ");
	scanf("%f", &x);
	if ((x * 2) > 30)
	{
		x = x + 4;
	}
	x = x / 2;
	x = x + 1;
	if ((x - 11) < (2 * x - 23))
	{
		x = x - 1;
	}
	printf("x = %.2f\n", x);
}
