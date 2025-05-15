//Structs - fisch.c

#include <stdio.h>
#include <stdbool.h>

struct fisch
{
	char name[255];
	char art[255];
	int zaehne;
	int alter;
	bool schuppen = 0;
	
};

void ausgabe(struct fisch *fisch1);

int main(void)
{
	struct fisch fisch1 = {"Snappy", "Piranha", 69, 5, 1};

	ausgabe(&fisch1);
	
	return 0;
}

void ausgabe(struct fisch *fisch1)
{
	if(fisch *fisch1 schuppen == 1)
	{
		printf("%s ist ein %s, er hat %i Zähne und ist %i Jahre alt. Er hat Schuppen.\n", fisch1->name, fisch1->art, fisch1->zaehne, fisch1->alter);
	}
	else
	{
		printf("%s ist ein %s, er hat %i Zähne und ist %i Jahre alt. Er hat keine Schuppen.\n", fisch1->name, fisch1->art, fisch1->zaehne);
	}
}

