#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

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
		gettimeofday(&start_time, NULL); //start the chronometer.
		val = fork();
		if (val == 0)
		{	//forwarding to dev/null
			int null_fd = open("/dev/null", O_WRONLY);
			if(dup2(null_fd, STDOUT_FILENO) == -1)
			{
				perror("dup");
				exit(NULL);
			}
			close(null_fd);



			execvp(command_name, (char *)NULL); //runs the command specified with no arguments.
			exit(NULL);//since the child exits after execution, they won't be able to create processes themselves.

		}
		else
		{
			wait();//the parent will wait for its children to finish.
		}
		gettimeofday(&end_time, NULL);//stop the chronometer.
		duration = (double)(end_time.tv_sec - start_time.tv_sec) * 1000.0 + (double)(end_time.tv_usec - start_time.tv_usec) / 1000.0;
		durations[i] = duration;
				
			
	}

	for (int i = 0; i < n; i++)
	{
		printf("It took process %d, %lf miliseconds.\n", i, durations[i]);
	}



	return 0;
}
