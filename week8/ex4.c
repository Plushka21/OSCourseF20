/**
	Anton Buguev BS19-02 
	a.buguev@innopolis.university
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	int *mem = NULL;
	size_t size = 0;
	struct rusage u;
	printf("Time in user mode \t Time in kernel mode \t Num of page faults(without I/O) \t Num of page faults(with I/O) \t Num of context switches\n");
	printf("\n");
	for(int i=0; i<10; i++)
	{
		size += 10*1024*1024;
		mem = realloc(mem, size);
		memset(mem, 0, size);
		
		getrusage(RUSAGE_SELF, &u);
		printf("%ld \t\t\t %ld \t\t\t %ld \t\t\t\t\t %ld \t\t\t\t %ld \n",
			u.ru_utime.tv_usec, u.ru_stime.tv_usec, u.ru_minflt, u.ru_majflt, u.ru_nvcsw + u.ru_nivcsw
		);
		
		sleep(1);
	}
	
	return 0;
}
