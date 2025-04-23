//Calvin Steinbach - Pinabfrage.c

#include <stdio.h>
#include <stdbool.h>

int main (void)
{
	int pin[4] = {0};
	int check_pin[4] = {0};
	bool entry = false;
	int sizeof_array = sizeof(pin) / sizeof(pin[0]);
	int i;


	printf("Neue PIN erstellen:\n");

	for (i = 1; i <= sizeof_array; i++)
	{
		printf("Bitte geben sie die %i. Ziffer an:\n", i);
		scanf("%i", &pin[i]); 
	
	}
	
	printf("Bitte PIN eingeben:\n");
	
	for (i = 1; i <= sizeof_array; i++)
	{
		scanf("%i", &check_pin[i]);
	}
	
	for (i = 1; i <= sizeof_array; i++)
	{
		if (pin[i] != check_pin[i])
		{
			entry = false; 
		}
		else
		{
			entry = true;
		}
	}

	if (entry == false)
	{
		printf("Zugang verwehrt");
	}
	else
	{
		printf("Zugang gestattet");
	}

	return 0;
}
