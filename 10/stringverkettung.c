//Calvin Steinbach - String Verkettung.c

#include <stdio.h>
#include <string.h>

int main(void)
{
	char ersterstring[20] = {"Blumen"};
	char zweiterstring[10] = {"wiese"};
	strcat(ersterstring, zweiterstring);

	printf("%s", ersterstring);

}
