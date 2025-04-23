// Calvin Steinbach - Countdown.c

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int zeit = 10;
	int zaehler;

	for (zaehler = 0; zaehler <= zeit; zaehler ++)
	{
		printf("%i\n", zaehler);
		sleep(1);

	}
	return 0;
}

