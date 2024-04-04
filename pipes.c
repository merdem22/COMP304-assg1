#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Please enter n and the command_name properly.");//ensuring proper command line arguments..
		return 1;
	}
	//get input.
	int n = atoi(argv[1]);
	char *command_name = argv[2];
	
	int val; 
	double durations[n];

	struct timeval start_time, end_time;
	double duration;

	for (int i = 0; i < n; i++)
	{
		val = fork();
		if (val == 0)
		{	
			gettimeofday(&start_time, NULL);
			execvp(command_name, (char *)NULL); //runs the command specified with no arguments.
			gettimeofday(&end_time, NULL);
			
			duration = (double)(end_time.tv_sec - start_time.tv_sec) * 1000.0 + (double)(end_time.tv_usec - start_time.tv_usec) / 1000.0;
			printf("Child executed in %lf seconds.");
			exit(NULL);
		}
		else
		{
			wait();//wait for child to finish.
		}		
			 

	}




	return 0;
}
