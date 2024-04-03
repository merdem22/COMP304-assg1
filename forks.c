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
	int parent_id = getpid();
	int pid;
	int i = 0;
	int level = 0; 
	
	printf("Main Process ID: %d, level: %d\n", parent_id, level);

	for (int i = 0; i < x; i++)
	{
		
		parent_id = getpid(); //we can get the parent id as the current process before calling fork will be the parent.
		int val = fork(); //create a child process here, anything below will be run concurrently with parent.
		if (val == 0) //we want to update the level only if we are in a child process.
		{
			level++;
		}
		
	}
	pid = getpid();
	if (level > 0)
	{
		printf("Process ID: %d, Parent ID: %d, Level: %d\n",pid, parent_id, level);
	}
	
	return 0;
}
