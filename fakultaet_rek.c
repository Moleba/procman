// calculates the faculty of a number
#include <math.h>   // sqrt
#include <stdio.h>  // printf
#include <stdlib.h> // exit
#include <string.h> // atoi
#include <time.h>   // gettimeofday

struct timeval begin, end;  // time for start and end
void stopTimeMeasure();     // function to stop measuring time

int fakultaet(int a);       // function to calculate the faculty of a number

int main(int argc, char *argv[])
{
     
    
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("Entering fakultaet_rek.exe\n");
    // Start measuring time
    gettimeofday(&begin, 0);
    
    if (argc != 2)
    {
        printf("ERROR\n");
        printf("Usage: %s.exe <number>\n", argv[0]);
        // Stop measuring time and calculate the elapsed time
        stopTimeMeasure();
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        return EXIT_FAILURE;
    }
    int a = atoi(argv[1]);
    if (a > 16)
    {
        printf("Ueberlauf 32-Bit Integer! Ergebnis Ungueltig!\n"); // Fehlerbehandlung Überlauf
        // Stop measuring time and calculate the elapsed time
        stopTimeMeasure();
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

        return EXIT_FAILURE;
    }
    else if (a < 0)
    {
        printf("Fakultaet von negativen Zahlen ist nicht definiert!\n"); // Fehlerbehandlung negative Zahlen
        // Stop measuring time and calculate the elapsed time
        stopTimeMeasure();
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

        return EXIT_FAILURE;
    }
    else
    {
        printf("%d! = %d\n", a, fakultaet(a));
    }
    // Stop measuring time and calculate the elapsed time
    stopTimeMeasure();
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    
    return EXIT_SUCCESS;
}

int fakultaet(int a)
{
    // recursive function to calculate the faculty of a number
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return a * fakultaet(a - 1);
    }
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