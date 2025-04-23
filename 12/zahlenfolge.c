//Calvin Steinbach - Dateiverarbeitung, zahlenfolge.c

#include <stdio.h>

int main(void)
{
	FILE *fp;
	int i;

	fp = fopen("zahlenfolge.txt", "w");

	if(fopen == NULL)
	{
		printf("Datei konnte nicht geöffnet werden");
	}
	else
	{
		for (i = 0; i < 10; i ++)
		{
			fprintf(fp, "%i\n", i);
		}
	}

	return 0; 

}
