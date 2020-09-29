/**
	Anton Buguev BS19-02
	a.buguev@innopolis.university
**/

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Number of elements in array
	int N;
	printf("Enter POSITIVE number of elements in array:\n");
	scanf("%d", &N);
	
	// Allocate memory for array of integers with N elements
	int* arr = malloc(N*sizeof(int));
	// Fill array in decreasing order
	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}
	printf("\n");	
	
	// Print all elements of array
	printf("%d elements in array starting from 0:\n", N);
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("\n");
	
	// Free memory	
	free(arr);
	printf("The memory allocated for the array has just freed\n");
	printf("\n");
}
