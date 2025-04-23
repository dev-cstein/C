//Calvin Steinbach - Übung Schleifen

#include <stdio.h>

int main(void)
{
	int a;
	
	printf("Zahl eingeben: ");
	scanf("%i", &a);

	while(a < 5)
	{
		if(a % 2 == 0)
		{
			a = a - 1;
		}
		else
		{
		a = a + 3;
		}
		printf("a = %i\n",a);
	}

}	
