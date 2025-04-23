//Calvin Steinbach - Dateiverarbeitung, alphabet.c

#include <stdio.h>
 
int main(void)
{
	FILE *fp;
	int i; 

	fp = fopen("alphabet.txt", "w");

	if(fp == NULL)
	{
		printf("Datei konnte nicht geöffnet werden!");
	}
	else
	{
		for(i = 0; i < 26; i ++)
		{
			fputc(i + 65, fp); 
		}
		
		fputc(10, fp);
		fclose(fp); 
	}
	
	
	return 0;
}
