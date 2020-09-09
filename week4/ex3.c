#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
			system(line);
		}
	}
	return 0;
}
