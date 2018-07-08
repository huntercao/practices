// gcc -g -Wall ./gdb_sample.c -o ./gdb_sample.out
// https://www.howtoforge.com/tutorial/how-to-debug-c-programs-in-linux-using-gdb/
// Execute with error below:
//	Program received signal SIGFPE, Arithmetic exception.
// 	0x0000000000400623 in main () at ./gdb_sample.c:13
#include <stdio.h>

int main()
{
    int out = 0, tot = 0, cnt = 0;
    int val[] = {5, 54, 76, 91, 35, 27, 45, 15, 99, 0};

    while(cnt < 10)
    {
        out = val[cnt];
        tot = tot + 0xffffffff/out;
        cnt++;
    }

    printf("\n Total = [%d]\n", tot);
    return 0;
}
