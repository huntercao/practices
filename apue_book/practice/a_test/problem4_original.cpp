// Code will runtime error below:
// 	$ ./a.out 
//	 File::Read(). 
//	 File::Read(). 
//	*** Error in `./a.out': double free or corruption (!prev): 0x00000000020fec20 ***
//	======= Backtrace: =========
//	/lib/x86_64-linux-gnu/libc.so.6(+0x77725)[0x7f3cd6323725]
//	/lib/x86_64-linux-gnu/libc.so.6(+0x7ff4a)[0x7f3cd632bf4a]
//	/lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7f3cd632fabc]
//	/lib/x86_64-linux-gnu/libc.so.6(fclose+0x103)[0x7f3cd6319313]
//	./a.out[0x4009c3]
//	./a.out[0x4008f3]
//	/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7f3cd62cc830]
#include <stdio.h>

class File
{
private:
	FILE *fd;
public: 
	File(const char * name)
	{
		fd = fopen(name, "r");
	}

	~File()
	{
		if(fd != NULL)
		{
			fclose(fd);
		}
	}

	void Read(void* buff, size_t n)
	{
		printf(" File::Read(). \n");
		fread(buff, 1, n, fd);
	} 
};

void foo(File f, void* buff, size_t n)
{
	f.Read(buff, n);
}

int main()
{
	char buff[100];
	File f("test.data");
	foo(f, buff, 4);
	foo(f, buff, 4);
	return 0;
}
