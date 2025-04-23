//Calvin Steinbach - Pointer, callbyreference.c

#include <stdio.h>

void berechne_endpreis(float *);

int main(void)
{
	float preis = 300.00;
	berechne_endpreis(&preis);
	printf("%.2f\n", preis);

	return 0;
}

void berechne_endpreis(float *ppt)
{
	*ppt = *ppt * 1.19;
}
