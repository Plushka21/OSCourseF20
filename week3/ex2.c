#include <stdio.h>
#include <stdlib.h>

// Swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
            // Compare neighbour elements and swap them if necessary
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    }
}

int main() {
    // Create array of 10 elements
    int arr[10];
    int size = 10;
    // Fill array with random numbers
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    // Print initial array
    printf("Initial array: \n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Sort array
    BubbleSort(arr, size);
    // Print sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}