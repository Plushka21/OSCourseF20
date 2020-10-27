/*
    Anton Buguev BS19-02
    a.buguev@innopolis.university
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(){
	int input = open("ex1.txt", O_RDONLY);
	
	int output = open("ex1.memcpy.txt", O_RDWR);
	
	int size = lseek(input, 0, SEEK_END);
	
	char *in = mmap(NULL, size, PROT_READ, MAP_PRIVATE, input, 0);
	
	ftruncate(output, size);
	char *out = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, output, 0);
	
	memcpy(out, in, size);
	
	close(input);
	close(output);
}
