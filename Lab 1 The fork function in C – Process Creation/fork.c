#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	fork();
	printf("Hello, testing the fork() \n PID = %d\n", getpid());
	
	return 0;
}
