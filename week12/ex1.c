#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(){
	int randdata = open("/dev/urandom", O_RDONLY);
	
	if (randdata < 0)
	{
    		printf("Error\n");
    		return 1;
	}
	
	else
	{
    		char string[20];
    		ssize_t result = read(randdata, string, sizeof string);
    		if (result < 0)
    		{
    			printf("Error\n");
    			return 2;
    		}
    		else{
    			FILE *res;
    			res = fopen("ex1.txt", "w+");
    			for (int i = 0; i < 20; i++) {
    				fprintf(res, "%c", string[i]);
    			}
    			fclose(res);
    		}
	}
	close(randdata);
}
