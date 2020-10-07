/**
	Anton Buguev BS19-02 
	a.buguev@innopolis.univeristy
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	int size = 0;
	int *mem = NULL;
	for (int i = 0; i < 10; i++){
		size += 10*1024*1024;
		mem = realloc(mem, size);
		sleep(1);
	}
}

/**
	si and so fields are equal 0 during execution because 0 blocks were swapped from or into memry
**/
