#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000


int main()
{
	int numbers[MAX_NUMBERS];
	int num_count = 0;

	//assign numbers to array from stdin.
	while (num_count < MAX_NUMBERS && scanf("%d", &numbers[num_count]) == 1)
	{
		num_count++;
		while(getchar() != '\n');

	}

	for (int i = 0; i < MAX_NUMBERS; i++)
	{
		printf("%d", numbers[i]); //print the numbers for debugging.
	}	

	
	return 0;
}
