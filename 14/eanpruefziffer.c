//Pointer - Prüfzifferberechnung

#include <stdio.h>

void datei_einlesen(int *artikelnummer, int *ean, float *preis, char bezeichnung[250]);
void pruefziffer_berechnen(int *ean);

int main(void)
{
    int artikelnummer;
    int ean;
    float preis;
    char bezeichnung[250];
    
    datei_einlesen(&artikelnummer, &ean, &preis, bezeichnung);
    
    return 0;
}

void datei_einlesen(int *artikelnummer, int *ean, float *preis, char bezeichnung[250])
{
    FILE *fp;
    
    fp = fopen("artikeldat.csv", "r");
    
    if(fp == NULL)
    {
        printf("Fehler, Datei konnte nicht geöffnet werden!");
    }
    else
    {
        while(fscanf(fp, "%i;%i;%f;%s", artikelnummer, ean, preis, bezeichnung) == 4)
        {
           printf("%i\t%i\t%.2f\t%s\n", *artikelnummer, *ean, *preis, bezeichnung);
        }
    }
    
    fclose(fp);
}

void pruefziffer_berechnen(int *ean);
