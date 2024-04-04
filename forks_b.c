#include <stdio.h>
#include <stdlib.h>


int main(){


	int val = fork();
	if (val == 0)
	{
		//the child will terminate immediately.
		exit(EXIT_SUCCESS);	
	}
	else
	{
		sleep(5);//the parent will remain running for 5 seconds, but its child has terminated itself turning into a zombie.
	}
	return 0;
}
