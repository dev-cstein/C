//Pointer - Übung Zahlenändern

#include <stdio.h>

void get_numbers(int *zahl1, int *zahl2);
void double_numbers(int *zahl1, int *zahl2);
void switch_and_output(int *zahl1, int *zahl2);

int main(void)
{
	int zahl1;
	int zahl2;
	
	get_numbers(&zahl1, &zahl2);
	printf("Zahl1 = %i\nZahl2 = %i\n", zahl1, zahl2);
	
	double_numbers(&zahl1, &zahl2);
	printf("Zahl1 * 2 = %i\nZahl2 * 2 = %i\n", zahl1, zahl2);
	
	switch_and_output(&zahl1, &zahl2);
	

	return 0;
}

void get_numbers(int *zahl1, int *zahl2)
{
	 printf("Bitte gib die erste Zahl ein:");
	 scanf("%i", zahl1);
	 printf("Biite gib die zweite Zahl ein:");
	 scanf("%i", zahl2);
}

void double_numbers(int *zahl1, int *zahl2)
{
	*zahl1 = *zahl1 * 2;
	*zahl2 = *zahl2 * 2;
}

void switch_and_output(int *zahl1, int *zahl2)
{
	int temp;

	temp = *zahl1;
	*zahl1 = *zahl2;
	*zahl2 = temp;

	printf("Zahl1 = %i\nZahl2 = %i\n", *zahl1, *zahl2);
}

