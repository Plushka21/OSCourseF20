/**
 * Anton Buguev BS19-02
 * a.buguev@innopolis.university
 */

#include <stdio.h>
#include <stdlib.h>

// Each page has it's own id and counter that consists of 32 bits
typedef struct page {
    int id;
    unsigned int counter;
} table; // All pages are in table

// Function that checks whether page is already in the table using id of page
int findPage(table *pages, int n, int id){

    // Go through the whole table
    for (int i = 0; i < n; i++){
        // If the same id has been found return it's index
        if (pages[i].id == id){
            return i;
        }
    }
    // Otherwise return -1
    return -1;
}

// Find position to allocate new page
int findPlace(table *pages, int n) {

    // Page with smallest counter will be removed
    unsigned int smallestCounter = 1<<31;
    // Index of page with smallest counter
    int smallestCounterIndex = 0;
    
    // Go through the whole table
    for (int i = 0; i < n; i++){
    
        // If there is free place in table return it's index
        if (pages[i].id == 0){
            return i;
        }
        
        // If counter of some page is smaller than smallest counter
        // Make the smallest counter equal to that counter and keep index of this page
        if (pages[i].counter < smallestCounter){
            smallestCounter = pages[i].counter;
            smallestCounterIndex = i;
        }
    }
    
    // If no free place was found return index of page with smallest counter
    return smallestCounterIndex;
}

int main() {

    // Number of page frames
    int n;
    printf("Enter number of page frames:\n");
    if (!scanf("%d", &n) || n <=0 ){
        printf("This is not positive integer, try again\n");
        exit(0);
    }

    // Table with page frames
    table *pages = calloc(n, sizeof(table));

    // Open file with input
    char *filename = "Lab 09 input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Input file is not found, try again\n");
        exit(0);
    }

    // Number of hits and misses
    int hit = 0;
    int miss = 0;
    // Id of page
    int id;

    // Read every page id
    while (fscanf(file, "%d", &id) == 1){
    
        // Check if page is already in the table
        int index = findPage(pages, n, id);
        
        // If page has not been found we increase number of misses and find position for this page
        if (index == -1){
            miss++;
            index = findPlace(pages, n);
            pages[index].id = id;
            pages[index].counter = 0;
        }
        
        // Otherwise we just increase number of hits
        else {
            hit++;
        }

        // Shift counters of each page to the right
        for (int i = 0; i < n; i++){
            pages[i].counter >>= 1;
        }
        
        // Add 1 from the left side to the counter of current page, i.e. add 2^31 in binary form
        pages[index].counter += 1<<31;

    } // End of the loop

    // Print results
    printf("Hits: %d\n", hit);
    printf("Misses: %d\n", miss);
    printf("Hit/Miss = %f\n", (double)hit/miss);

    // Free memory from pages and close file
    free(pages);
    fclose(file);

    return 0;
}
