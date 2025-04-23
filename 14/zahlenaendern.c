//Pointer - Übung Zahlenändern

#include <stdio.h>
#include <string.h>

float get_numbers(float*, float*);
float double_numbers(float*, float*);
float switch_and_output(float*, float*);

int main(void)
{
	float *zahl_1 = -1.0;
	float *zahl_2 = -1.0;

	
	return 0;
}

float get_numbers(float *zahl_1, float *zahl_2)
{
	do
	{
		printf("Bitte erste Zahl eingeben:\n");
		scanf("%f", &zahl_1);
		printf("Bitte zweite Zahl eingeben:\n");
		scanf("%f", &zahl_2);
		
	}while(*zahl_1 == -1 || *zahl_2 == -1); 
}

float double_numbers()
{

}

float switch_and_output()
{

}
