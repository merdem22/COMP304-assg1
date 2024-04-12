#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000


int main(int argc, char* argv[])
{
	int numbers[MAX_NUMBERS];
	int num_count = 0;


	if (argc != 3)
	{
		//ensure propper command line arguments.
		printf("Please enter x and n as command line arguments.");
		return 1;
	}


	//assign numbers to array from stdin.
	while (num_count < MAX_NUMBERS && scanf("%d", &numbers[num_count]) == 1)
	{
		num_count++;
		while(getchar() != '\n');

	}
	

	int x = argv[1];
	int processNum = argv[2];

	int arraySize = MAX_NUMBERS/processNum;
	
	
	for (int i = 0;	i < processNum; i++)
	{
		int val = fork();
		if (val == 0)
		{	
			//search the array.
			int startIndex = arraySize * i;
			int endIndex = arraySize * (i+1);
			for (int j = startIndex; j < endIndex; j++)
			{
				if (numbers[j] == x)
				{
					printf("X found.");
					exit(0);
				}
			}
			exit(1);
		}
		else
		{	//parent waits for children.
			wait();
		}
	}

	
	return 0;
}
