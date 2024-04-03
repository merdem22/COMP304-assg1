#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	
	

		
	if (argc != 2)//ensure command line arguments are entered properly.
	{
		printf("Please enter a single number as a command line argument to determine how many child processes will be created.");
		return 1;
	}
	

	int x = atoi(argv[1]);
	int pid; //this variable will store the process id.

	while (x > 0)
	{	
		
		fork();
		pid = getpid();
		printf("The process id is: %d\n", pid);
		x--;
	}

	return 0;
}
