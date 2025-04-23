// Calvin Steinbach - program01

#include <stdio.h>	//Einbinden der benötigten Libary

int main(void)
{
	char name[50];	//Deklarierung Zeichen-Array 
	int age;	// Deklarierung Integer-Variable	
	
	printf("Gib deinen Namen ein: \n");	//Ausgabe
	scanf("%s", name);	//Entgegennahme des Namen
	
	printf("Gib dein Alter ein: \n");	//Ausgabe
	scanf("  %d", &age);	//Entgegennahme des Alters

	printf("Hallo %s, du bist %i Jahre alt!\n", name, age);	//Finale Ausgabe

	return 0;

}
