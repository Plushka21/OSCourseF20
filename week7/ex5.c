/**
	Anton Buguev BS19-02
	a.buguev@innopolis.university
**/

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Original line::
	// char **s;
	// Changed line: 
	char **s = (char**)malloc(sizeof(char*)); // We need to allocate memory for this pointer
	
    	char foo[] = "Hello World";
    	*s = foo;
    	
    	// Original line:
    	// printf("s is %s\n", s); 
    	// Changed line:
    	printf("s is %s\n", *s); // We need to get value which this pointer points to
    	
    	// *s and s[0] is actually the same, so the output will be the same
    	s[0] = foo;
    	printf("s[0] is %s\n", s[0]);
    	return(0);
}
