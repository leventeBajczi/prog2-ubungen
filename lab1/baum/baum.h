#ifndef BAUM_H
#define BAUM_H

// Element des Baumes
typedef struct Messung{
    int Data;
    int Anzahl;
    struct Messung *Right, *Left;
} Knote;

// Funktiondeklarationen
// LaborAufgaben
int Baum_Add(Knote **Head, int Data); // Neue Element zur Baum hinfügen
void Baum_Print(Knote *Head);		// Alle Elemente ausschreiben

int Baum_Min(Knote *Head); 			// Minimalwert zurückgeben
int Baum_Max(Knote *Head);			// MAximalwert zurückgeben
void Baum_Delete(Knote **Head);		// Baum Loschen, Speicherplatz freigeben

#endif //BAUM_H
