#include <stdio.h>
#include <stdlib.h>


int main(){


	int val = fork();
	if (val == 0)
	{
		//this is where the code for the child process will be executed.
		exit(EXIT_SUCCESS);	
	}
	else
	{
		sleep(5);
	}
	return 0;
}
