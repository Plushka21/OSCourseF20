#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readData(FILE *input, int *E, int *A, int **C, int **R, int p, int r) {
    char string[256];

    // Fill matrix E
    fgets(string, 256, input);
    char *n = strtok(string, " ");
    for (int i = 0; i < r; i++) {
        E[i] = atoi(n);
        if (n != NULL) {
            n = strtok(NULL, " ");
        }
    }

    fgets(string, 256, input); //Read empty string

    // Fill matrix A
    fgets(string, 256, input);
    n = strtok(string, " ");
    for (int i = 0; i < r; i++) {
        A[i] = atoi(n);
        if (n != NULL) {
            n = strtok(NULL, " ");
        }
    }
    fgets(string, 256, input); //Read empty string

    // Fill matrix C
    for (int i = 0; i < p; i++) {
        fgets(string, 256, input);
        char *n = strtok(string, " ");
        for (int j = 0; j < r; j++) {
            C[i][j] = atoi(n);
            if (n != NULL) {
                n = strtok(NULL, " ");
            }
        }
    }
    fgets(string, 256, input); //Read empty string

    // Fill matrix R
    for (int i = 0; i < p; i++) {
        fgets(string, 256, input);
        char *n = strtok(string, " ");
        for (int j = 0; j < r; j++) {
            R[i][j] = atoi(n);
            if (n != NULL) {
                n = strtok(NULL, " ");
            }
        }
    }
}

int main(){
    int *E; // Resources in existence,
    int *A; // Available resources,
    int **C; // Current allocation,
    int **R; // Request matrix
    FILE *input;



    // Change name of input file here
    input = fopen("input_ok.txt", "r");



    char string[256];

    int p, r; // Number of processes and resources
    fgets(string, 256, input);

    // Get number of resources and processes
    char *n = strtok(string, " ");
    p = atoi(n);
    n = strtok(NULL, " ");
    r = atoi(n);
    fgets(string, 256, input); //Read empty string

    // Allocate memory for matrices
    E = malloc(r * sizeof(int));
    A = malloc(r * sizeof(int));
    C = (int **)malloc(p*sizeof(int *));
    R = (int **)malloc(p*sizeof(int *));
    // If F_i = 0, process is not finished, otherwise it is finished
    int *F = malloc(p * sizeof(int));
    for(int i = 0; i < p; i++) {
        C[i] = (int *)malloc(r*sizeof(int));
        R[i] = (int *)malloc(r*sizeof(int));
        F[i] = 0;
    }

    readData(input, E, A, C, R, p, r);
    fclose(input);

    int less; // If all numbers in a row of matrix R are less than numbers in A,
    // we can give resources to that process and finish it
    int somethingChanged = 1; // If at least one process was finished
    // we need to go through the whole matrix R againg

    while (somethingChanged == 1){
        somethingChanged = 0;
        for (int i = 0; i < p; i++){
            if (F[i] != 1) {
                for (int j = 0; j < r; j++){
                    int req = R[i][j];
                    int a = A[j];
                    if (req <= a){
                        less = 1;
                    } else {
                        less = 0;
                        break;
                    }
                }
                if (less == 1){
                    for (int j = 0; j < r; j++){
                        int c = C[i][j];
                        int a = A[j];
                        A[j] += c;
                        a = A[j];
                        printf("%d ", a);
                    }
                    F[i] = 1;
                    somethingChanged = 1;
                    printf("\n");
                }
            }
        }
    }

    //
    int dl = 0;
    for (int i = 0; i < p; i++){
        if (F[i] == 0){
            dl++;
        }
    }

    if (dl == 0){
        FILE *output = fopen("output_ok.txt", "w+");
        fprintf(output, "No deadlock");
        fclose(output);
    } else{
        FILE *output = fopen("output_dl.txt", "w+");
        fprintf(output, "%d processes are deadlocked", dl);
        fclose(output);
    }

}