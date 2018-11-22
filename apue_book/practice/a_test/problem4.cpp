#include <stdio.h>

class File
{
private:
	FILE *fd;
public: 
	File(const char * name)
	{
		fd = fopen(name, "r");
		printf("File::File(). fd = %d\n", fileno(fd));
	}

	~File()
	{
		printf("~File::File(). fd = %d\n", fileno(fd));
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
	printf(" foo() in. \n");
	f.Read(buff, n);
	printf(" foo() out. \n");
}

int main()
{
	char buff[100];
	File f("test.data");
	printf("main(). Before first foo()\n");
	foo(f, buff, 4);
	printf("main(). Before second foo()\n");
	foo(f, buff, 4);
	printf("main(). Before return.\n");
	return 0;
}
/*
File::File(). fd = 3
main(). Before first foo()
 foo() in. 
 File::Read(). 
 foo() out. 
~File::File(). fd = 3
main(). Before second foo()
 foo() in. 
 File::Read(). 
 foo() out. 
~File::File(). fd = -1
*** Error in `./a.out': double free or corruption (!prev): 0x0000000000974c20 ***
*/
