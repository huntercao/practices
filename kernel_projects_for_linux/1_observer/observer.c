#include 	<stdio.h>
#include 	<stdlib.h>	
#include	<sys/time.h>
#include	<time.h>
#include	<string.h>
#include	<unistd.h>

typedef enum 
{
	STANDARD,
	SHORT,
	LONG,
	UNKNOWN
}report_type;
 
#define LB_SIZE 80

void sampleLoadAvg()
{
	char *args[6];
	char lineBuf[LB_SIZE];
	FILE *thisProcFile = fopen("/proc/loadavg", "r");
	if( thisProcFile == NULL)
	{
		perror("cannot open file /proc/loadavg");
		return;
	}

	fgets(lineBuf, LB_SIZE + 1, thisProcFile);
	args[0] = strtok(lineBuf, " "); 	 	
	for(int i = 1; i <= 5; i++)
	{
		args[i] = strtok(NULL, " /");	
		printf("Index[%d]\t:\t%s\n", i, args[i]);
	}
	fclose(thisProcFile);
}

int main(int argc, char *argv[])
{
	char repTypeName[16];
	int interval, duration, iteration;
	struct timeval now;

	report_type reportType = STANDARD;
	strcpy(repTypeName, "Standard");
	if(argc > 1)
	{
		char c1, c2;
		sscanf(argv[1], "%c%c", &c1, &c2);
		if(c1 != '-')
		{
			fprintf(stderr, "usage: observer [-s][-l int dur]\n");
			exit(1);
		}
		if(c2 == 's')
		{
			reportType = SHORT;
			strcpy(repTypeName, "Short");
		}
		if(c2 == 'l')
		{
			reportType = LONG;
			strcpy(repTypeName, "Long");
			interval = atoi(argv[2]);
			duration = atoi(argv[3]);
		}
	}

	gettimeofday(&now, NULL);
	printf("Status report type %s at %s\n",
			repTypeName, ctime(&(now.tv_sec)));
	
	FILE *thisProcFile = fopen("/proc/sys/kernel/hostname", "r");
	char lineBuf[LB_SIZE];
	fgets(lineBuf, LB_SIZE+1, thisProcFile);
	printf("Machine hostname: %s\n", lineBuf);
	fclose(thisProcFile);

	while(iteration < duration)
	{
		sleep(interval);
		sampleLoadAvg();
		iteration += interval;
	}

	exit(0);
	
}
