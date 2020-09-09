#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
/*
* each fork creates 2 processes
* so if we call fork 3 times, 8 processes will be created
* and if we call fork 5 times, 32 processes will be created
*/
	for (int i = 0; i < 5; i++){
		fork();
	}
	sleep(5);
}
