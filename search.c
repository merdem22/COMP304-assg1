#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_NUMBERS 1000


int main(int argc, char* argv[])
{
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
	
	int x = atoi(argv[1]);
	int processCount = atoi(argv[2]);
	int portionSize = numCount/processCount;
	int remainder = numCount % processCount;
	
	for (int i = 0;	i < processCount; i++)
	{
		int val = fork();
		if (val == 0)
		{	
			//search the array.
			int startIndex = portionSize * i;
			int endIndex;
			if (i == processCount - 1) //managing the windows borders.
			{
				endIndex = numCount;
			}
			else
			{	endIndex = startIndex + portionSize + (i < remainder ? 1 : 0); 
			}
			for (int j = startIndex; j < endIndex; j++)
			{
				if (numbers[j] == x)
				{
					printf("X found.\n");
					exit(0);
				}
			
			}
			//not found
			printf("Not found, for process %d\n", i+1);
			exit(1);
		}
	}

	wait(NULL); //wait for children
	
	//kill(0, SIGKILL); //kill all remaining children. 


	
	return 0;
}
