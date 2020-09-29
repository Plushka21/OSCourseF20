/**
	Anton Buguev BS19-02
	a.buguev@innopolis.university
**/

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>


// Own implementation of realloc()
void *MyRealloc(int *ptr, size_t new_size) {
    // If pointer is NULL this call is equivalent to malloc()
    if (ptr == NULL) {
        return malloc(new_size*sizeof(size_t));
    }

    // If size is 0 this call is equivalent to free()
    if (new_size == 0){
        free(ptr);
        return NULL;
    }

    // Otherwise we create new array and copy all elemnts from old array inside it
    int *arr = malloc(new_size*sizeof(size_t));
    int old_size = malloc_usable_size(ptr);
    // If new_size is bigger than old_size all new elements will be 0
    // In other case not all elements will be copied
    for (int i = 0; i < old_size; i++){
    	arr[i] = ptr[i];
    }

    // Free memory and return new array
    free(ptr);
    return arr;
}

int main(){ 
    // Original size of array
    int old_size;
    printf("Enter POSITIVE number of elements in array: \n");
    scanf("%d", &old_size);

    // Allocate memory for new array and fill it with numbers starting from 0
    int* arr = malloc(old_size*sizeof(int));
    for (int i = 0; i < old_size; i++){
        arr[i] = i;
    }
    printf("\n");
    
    //Print original array
    printf("Original array arr:\n");
    for (int i = 0; i < old_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");


    // Create 3 copies of original array
    // First to demonstrate what happens if ptr == NULL
    int *a1 = malloc(old_size*sizeof(int));
    // Second to demonstrate what happens if new_size == 0
    int *a2 = malloc(old_size*sizeof(int));
    // Third to demonstrate what happens if ptr != NULL and new_size != 0
    int *a3 = malloc(old_size*sizeof(int));
    
    // Copy elements from old array into new
    for (int i = 0; i < old_size; i++) {
    	a1[i], a2[i], a3[i] = arr[i];
    }
    
    // New size of array
    int new_size;
    printf("Enter POSITIVE number, new size of array:\n");
    scanf("%d", &new_size);
    
    // Call function for those 3 arrays
    a1 = MyRealloc(NULL, new_size);
    a2 = MyRealloc(a2, 0);
    a3 = MyRealloc(a3, new_size);

    // Print results
    printf("Array a1 = MyRealloc(Null, %d):\n", new_size);
    printf("Array a1 is filled with nulls because that call was equivalent to malloc()\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");
    printf("\n");

    printf("Array a2 = MyRealloc(arr, 0):\n");
    for (int i = 0; i < new_size; i++) {
        if (a2 == NULL) {
            printf("Array a2 is empty since new size is 0");
            break;
        }
        printf("%d ", a2[i]);
    }
    printf("\n");
    printf("\n");

    printf("Array a3 = MyRealloc(arr, %d):\n", new_size);
    if (old_size > new_size){
    	printf("Array a3 = arr - %d last elements \n", old_size - new_size);
    }
    else{
    	printf("Array a3 = arr + %d new elements \n", new_size - old_size);
    }
    for (int i = 0; i < new_size; i++) {
        if (a3 == NULL) {
            printf("Array a3 is empty");
            break;
        }
        printf("%d ", a3[i]);
    }
    printf("\n");
}

