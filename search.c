#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_NUMBERS 1000


int main(int argc, char* argv[])
{
	
	//set up the arguments
	int x = atoi(argv[1]);
	int processCount = atoi(argv[2]);
	pid_t childrenPIDS[processCount]; //get the pids from this array once its time to kill the children.

	int numbers[MAX_NUMBERS];
	int numCount = 0;

	if (argc != 3)
	{
		//ensure propper command line arguments.
		printf("Please enter x and n as command line arguments.");
		return 1;
	}

	//assign numbers to array from stdin.
	while (numCount < MAX_NUMBERS && scanf("%d", &numbers[numCount]) == 1)
	{
		numCount++;
		while(getchar() != '\n');

	}
	
	int portionSize = numCount/processCount;
	int remainder = numCount % processCount;
	
	for (int i = 0;	i < processCount; i++)
	{
		int val = fork();
		childrenPIDS[i] = val;
		if (val == 0)
		{	
			
			int startIndex = portionSize * i;
			int endIndex;
			if (i == processCount - 1) //setting up the borders of the array portion.
			{
				endIndex = numCount;
			}
			else
			{	endIndex = startIndex + portionSize + (i < remainder ? 1 : 0); 
			}
			for (int j = startIndex; j < endIndex; j++) //search the portion.
			{
				if (numbers[j] == x)
				{
					printf("Process with ID: %d has found X: %d at index: %d\n", getpid(), x, j);
					exit(0);
				}
			
			}
			//not found
			printf("Process with ID: %d failed to find a match.\n", getpid());
			exit(1);
		}
		else
		{	int status;
			waitpid(childrenPIDS[i], &status, 0); //wait for the current child to finish.
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0) //if the process exits with code 0.
			{
				for (int j = 0; j < i+1; j++)//kill the children processes.
				{
					if (j!=i)
					{
						kill(childrenPIDS[j], SIGKILL);
						printf("Process with ID: %d is killed.\n", childrenPIDS[j]);
					}
				}
				break;
			}
			
		}
	}
	
	return 0;
}
