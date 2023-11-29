// calculates the faculty of a number that is smaller than 17
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// time for start and end
#include <time.h>

struct timeval begin, end;
void stopTimeMeasure();

int fakultaet(int a){
    if(a >= 0){
        int temp_fak = 1;               // Anlegen lokaler Variable zur Speicherung der Fakultät
        for(int i = 1; i <= a; i++){    // Iterieren bis a
            temp_fak *= i;              // Multiplizieren der Elemente von 1 bis a
            if(temp_fak < 0){
                printf("Ueberlauf 32-Bit Integer! Ergebnis Ungueltig!\n");  // Fehlerbehandlung Überlauf
                return 0;
            }
        }
        return temp_fak;                // Rückgabe der Fakultät von a
    }
    return 0;                           // Fakultät von negativen Zahlen ist nicht definiert
}

int main(int argc, char *argv[])
{
    // Start measuring time
    gettimeofday(&begin, 0); 
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    printf("Entering fakultaet.exe\n");
    if (argc != 2)
    {
        printf("ERROR\n");   
        printf("Usage: %s <number>\n", argv[0]);
        // Stop measuring time and calculate the elapsed time
        stopTimeMeasure();
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        return EXIT_FAILURE;
    }
    double a = atof(argv[1]);   
    if(fmod(a,1) != 0){
        printf("%f! = not defined for not whole values\n", a);      // Fehlerbehanadlung nicht ganze Zahlen
    }else if (a < 0){
        printf("%f! = not defined negative values\n", a);           // Fehlerbehandlung negative Zahlen
    }else{
        printf("%d! = %d\n", (int)a, fakultaet(a));
    }
    // Stop measuring time and calculate the elapsed time
    stopTimeMeasure();
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    return EXIT_SUCCESS;
}

void stopTimeMeasure()
{
    gettimeofday(&end, 0);  // Stop measuring time
    // Calculate the elapsed time
    long seconds = end.tv_sec - begin.tv_sec;   
    long microseconds = end.tv_usec - begin.tv_usec;    
    long elapsed = seconds*1e6 + microseconds;  // elapsed time in microseconds
    
    printf("\nTime measured: %d mus.\n", elapsed);
}