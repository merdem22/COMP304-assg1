#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	
	if (argc != 2)
	{
		printf("Please enter a single number as a command line argument to determine how many child processes will be created.");
		return 1;
	}


	int x = atoi(argv[1]);

	while (x > 0)
	{
	
		printf("x: %d\n", x);
		x--; 
	}

	return 0;
}
