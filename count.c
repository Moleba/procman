// prints the amount of chars in a given string
#include <stdio.h>  // printf
#include <stdlib.h> // exit
#include <string.h> // strlen, atoi
#include <time.h>   // gettimeofday

struct timeval begin, end;  // time for start and end

int main(int argc, char *argv[])
{
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("Entering count.exe\n");
    gettimeofday(&begin, 0);    // Start measuring time

    // Check if the number of arguments is corrects
    if (argc != 2)
    {
        printf("ERROR\n");   
        printf("Usage: %s.exe <string>\n", argv[0]);
        // Stop measuring time and calculate the elapsed time
        stopTimeMeasure();
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        return EXIT_FAILURE;
    }

    printf("String: %s\n", argv[1]);
    printf("Length: %ld\n", strlen(argv[1]));
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