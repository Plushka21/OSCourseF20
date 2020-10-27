/*
    Anton Buguev BS19-02
    a.buguev@innopolis.university
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	FILE *file;
	file = stdout;
	char str[] = "Hello";
	setvbuf(file, str, _IOLBF, sizeof(str));
	for (int i = 0; i < 5; i++) {
		fprintf(file, "%c", str[i]);
		sleep(1);
	}
	printf("\n");
}
