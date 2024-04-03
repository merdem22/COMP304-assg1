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
	int i = 0;
	int level = 0; 
	
	printf("Main Process ID: %d, level: %d\n", getpid(), level);

	for (int i = 0; i < x; i++)
	{
		
		int val = fork(); 
		if (val == 0)//this block will only be executed in the child process.
		{
			level++;
			printf("Process ID: %d, Parent ID: %d, Level: %d\n", getpid(), getppid(), level);	
	
		}
		else
		{
			wait(NULL);
		}

		
	}
	
	return 0;

}
