#include "../../apue.2e/include/apue.h"

int
main(void)
{
	printf("Hello world from process ID %d\n", getpid());
	exit(0);
}
