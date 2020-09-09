#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// This program executes until you type 'stop'
	char line[100];
	while(1)
	{
		scanf("%100s", line);
		if (!strcmp(line,"stop")){
			break;
		}
		else{
			if (fork() == 0) {
			system(line);
			break;
		}
		}
	}
	return 0;
}
