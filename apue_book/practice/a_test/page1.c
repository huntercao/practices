#include "../../apue.2e/include/apue.h"
#define swap_int(left, right) int temp; temp = left; \
				left = right; right = temp; 
#define swap_generic(x, y) do \
	{ unsigned char swap_temp_buffer[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
	  memcpy(swap_temp_buffer, &y, sizeof(x)); \
	  memcpy(&y, &x,               sizeof(x)); \
	  memcpy(&x, swap_temp_buffer, sizeof(x)); \
	} while(0); 

int
main(void)
{
	char *p = "12345";
	printf("strlen(p) = %zd\n", strlen(p));
	printf("sizeof(p) = %zd\n", sizeof(p));

	char q[] = "12345"; 
	printf("strlen(q) = %zd\n", strlen(q));
	printf("sizeof(q) = %zd\n", sizeof(q));

	int left = 1, right = 2;
	printf("before swap_int(): left = %d, right = %d\n", left, right);
	swap_int(left, right);
	printf("after swap_int(): left = %d, right = %d\n", left, right);

	swap_generic(left, right);
	printf("after swap_generic(): left = %d, right = %d\n", left, right);

	float float_temp = 3.0f; 
	printf("before swap_generic(): left = %d, float_temp = %f\n", left, float_temp);
	swap_generic(left, float_temp);
	printf("after swap_generic(): left = %d, float_temp = %f\n", left, float_temp);


	exit(0);
}
