#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct timeval begin, end;
void stopTimeMeasure();


int main(int argc, char *argv[])
{
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("Entering root.exe\n");
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
    printf("(%d)^1/2 = %f\n", a, sqrt(a));
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

