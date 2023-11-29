// mit ececlp() ein Programm starten
#include <unistd.h>   //fork
#include <sys/wait.h> // wait
#include <stdio.h>    // printf
#include <stdlib.h>   // exit
#include <string.h>   // strcmp

int main(int argc, char *argv[])
{
    char program[100];
    char parameter[100];


    printf("Enter a program to start (\"exit\" for exit): ");
    scanf("%s", program);
    while(strcmp(program, "exit") != 0){
        if(program[0] != '.'){
            char* programcopy = malloc(strlen(program) +1);
            strcpy(programcopy, program);
            program[0] = '.';
            program[1] = '/';
            for(int i = 0; i < strlen(program); i++){
                program[2+i] = programcopy[i];
            }
        }

        printf("Enter a parameter: ");
        scanf("%s", parameter);
        

        printf("Program: %s\t", program);
        printf("Parameter: %s\n", parameter);

        pid_t pid;
        int child_stat = 0;
        switch (pid = fork()){
        case -1:
            perror("fork()");
            return EXIT_FAILURE;
        case 0:
            execlp(program, program, parameter, NULL);
            /*
            Nur der Kindprozess erreicht diese Codezeile, falls exec nicht funktioniert hat.
            Ist dies der Fall muss das geforkte Programm beendet werden, da es eine Kopie des
            Elternprozesses ist. 
            */
            printf("Failure execlp ...\n");
            printf("No such programfile! \n");
            return EXIT_FAILURE;            
        default:
            if (waitpid(pid, &child_stat, 0) != pid){
                perror("waitpid()");
                return EXIT_FAILURE;
            }
        }
        printf("Enter a program to start (\"exit\" for exit): ");
        scanf("%s", program);
    }
    printf("Program aborted!\n");
    return EXIT_SUCCESS;
}