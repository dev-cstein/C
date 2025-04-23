//Calvin Steinbach - Strings zusammenführen

#include <stdio.h>

int main(void)
{

	char vorname[10] = {""};
	char nachname[10] = {""};
	char zusammengesetzt[100] = {""};
	int i;
	int j;
	
	printf("Bitte gib deinen Vornamen ein:\n");
	scanf("%s", vorname);
	printf("Bitte gib deinen Nachnamen ein:\n");
	scanf("%s", nachname);

	for(i = 0; vorname[i] != '\0'; i++)
	{
		zusammengesetzt[i] = vorname[i];
	}

	for(j = 0; nachname[j] != '\0'; j++)
	{
		zusammengesetzt[i++] = nachname[j];
	}

	printf("%s\n", zusammengesetzt);
	

	return 0;
}
