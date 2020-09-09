#include <stdio.h>
#include <unistd.h>

int main()
{

	/*
	* fork() returns to parent PID of child and 0 to child
	* getpid() returns PID of process
	* in every new process PId increases by 1
	*/
	
	int n = fork();
	if (n==0){
		printf ("Hello from parent [%d-%d]\n", getpid(), n);
	}
	else{
		printf ("Hello from child [%d-%d]\n", getpid(), n);
	}
}
