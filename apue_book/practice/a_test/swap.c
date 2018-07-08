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

	float float_temp = 3.0f; 
	//printf("before swap_generic(): left = %d, float_temp = %f\n", left, float_temp);
	//swap_generic(left, float_temp);
	//printf("after swap_generic(): left = %d, float_temp = %f\n", left, float_temp);

	//unsigned char testarray[-1];
	//printf("sizeof(testarray[-1] = %d\n", sizeof(testarray));	
	int x = 1;
	float y = 2.0d;
	printf("sizeof(int) = %zd\n", sizeof(int));	
	printf("sizeof(float) = %zd\n", sizeof(float));	
	printf("sizeof(double) = %zd\n", sizeof(double));	
	{ unsigned char swap_temp_buffer[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
	  printf("sizeof(testarray[-1]) = %zd\n", sizeof(swap_temp_buffer));	
	  memcpy(swap_temp_buffer, &y, sizeof(x)); \
	  memcpy(&y, &x,               sizeof(x)); \
	  memcpy(&x, swap_temp_buffer, sizeof(x)); \
	}
	// Below code will cause gcc error:
	// error: size of array ‘negative_array’ is negative
	// unsigned char negative_array[-2];
	exit(0);
}
