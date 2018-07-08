#include "../../apue.2e/include/apue.h"
#define swap_int(left, right) int temp; temp = left; \
				left = right; right = temp; 
#define swap_generic(x, y) do \
	{ unsigned char swap_temp_buffer[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
	  memcpy(swap_temp_buffer, &y, sizeof(x)); \
	  memcpy(&y, &x,               sizeof(x)); \
	  memcpy(&x, swap_temp_buffer, sizeof(x)); \
	} while(0); 

void	myfree(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
} 
int
main(void)
{
	void * p;
	int i = 1;
	char * pMalloc = malloc(12); 
	printf("Address of pMalloc = %p\n", pMalloc);
	free(pMalloc);
	pMalloc = NULL;
	pMalloc = malloc(13);
	printf("Address of pMalloc = %p\n", pMalloc);
	myfree(pMalloc);

	char * pch = "123451234512345123451234512345123451234512345123451234512345";
	printf("Address of pch = %p\n", pch);
	// Below code will cause error below:
	// Program received signal SIGABRT, Aborted.
	// 	0x00007ffff7a43418 in __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:54
	//	54	../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
 
	free(pch);
	printf("Address of pch = %p\n", pch);
	myfree(pch);
	printf("Address of pch = %p\n", pch);
	p = &i; 
	printf("Content of i = %d\n", i);
	myfree(p);
	
	//printf("Content of i = %d\n", i);
	exit(0);
}
