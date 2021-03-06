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
	char *token;
	const char s[2] = " ";
	char lineBuf[LB_SIZE];
	FILE *thisProcFile = fopen("/proc/loadavg", "r");
	if( thisProcFile == NULL)
	{
		perror("cannot open file /proc/loadavg");
		return;
	}

	memset(lineBuf, 0, LB_SIZE);	

	fgets(lineBuf, LB_SIZE + 1, thisProcFile);
	printf("the linBuf of loadavg: %s\n", lineBuf);

	token = strtok(lineBuf, s); 	 	
	int index = 0; 
	while( token != NULL ) 
	{
		printf( "Index %d: %s\n", index++, token);
    
		token = strtok(NULL, s);
   	}

	fclose(thisProcFile);
}

int main(int argc, char *argv[])
{
	char repTypeName[16];
	int interval = 0, duration = 0, iteration = 0;
	struct timeval now;

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
			strcpy(repTypeName, "Short");
		}
		if(c2 == 'l')
		{
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
