#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <split.h>

void verarbeitung(FILE *input);
void ausgabekoerper();

int main(void)
{
	FILE *input; // Pointer auf Datei

	verarbeitung(input);
}

void verarbeitung(FILE *input)
{
	FILE *output;
	char *eof; //zeigt ob fgets erfolgreich war
	char temp[255]; //Zwischenspeicher für aktuell gelesene Zeile
	char dateiformat[5] = ".txt"; //Dateiendung um Datei erstellen zu können
	
	char knr[20], datum[20], einzelpreis[20]; //Zwischenspeicher für split funktion
	

	int laenge = 0; //zählt wieviele Zeichen bei split verbraucht wurden 123; --> int laenge = 4
	
	int kunde, kundennummer; //Zum vergleich der aktuellen und vorherigen Nummer
	float preis, gesamtumsatz; 
	
	input = fopen("bestellungen.csv", "r"); //Öffnen der CSV im Lesemodus

	if(input == NULL) 
	{
		printf("Fehler beim öffnen der Datei.");
	}
	else
	{
		eof = fgets(temp, 255, input); //fgets()speichert erste Zeile, char *eof ist ein hilfspointer ob fgets geliefert hat

		while(eof != NULL) //solange Daten vorhanden sind
		{
			laenge = split(temp, knr, ';'); //splittet kundennummer aus der 1.Zeile und setzt laenge ggf. zurück
			kunde = atoi(knr); // cast von string to integer
			
			kundennummer = kunde; //speichert die vorherige Kundennummer in Kundennummer

			gesamtumsatz = 0;//Setzt die Variable wieder auf Null für die nächste Gruppe
		
			while(eof != NULL && kunde == kundennummer) // prüft ob man sich noch in der Gruppe befindet
			{
				laenge += split(temp + laenge, datum, ';'); //splittet das datum aus der 1. zeile
				laenge += split(temp + laenge, einzelpreis, ';' ); //splittet den einzelpreis aus der 1 zeile

				preis = atof(einzelpreis); //cast string to float
				gesamtumsatz += preis; //Gesamtumsatz mit preis erhöhen

				ausgabekoerper(datum, preis, output);

				eof = fgets(temp, 255, input);//Neuen Datensatz holen
				laenge = split(temp, knr, ';'); //splittet kundenummer aus neuen datensatz für gruppenprüfung etc. 
				kunde = atoi(knr);	//cast string to integer
			}

			ausgabefluss(gesamtumsatz, output);
			fclose(output);
		}
	}	


}
