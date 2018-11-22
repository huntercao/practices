// Need compile with: $ gcc ./problem2.cpp -lstdc++
// To avoid below error:
//	/tmp/ccGMKhSa.o: In function `A::~A()':
//	problem2.cpp:(.text._ZN1AD2Ev[_ZN1AD5Ev]+0x35): undefined reference to `operator delete(void*)'
/* Result of running.
A::foo
A::foo
B::foo
B::boo
A::boo
A::boo 
*/
#include <stdio.h>

class A
{
public:
	A()
	{
		foo();
	}
	virtual ~A()
	{
		boo();
	}
	virtual void foo()
	{
		printf("A::foo\n");
	}
	virtual void boo()
	{
		printf("A::boo\n");
	}
};

class B : public A
{
public:
	B()
	{
		foo();
	}
	virtual ~B()
	{
		boo();
	}
	virtual void foo()
	{
		printf("B::foo\n");
	}
	virtual void boo()
	{
		printf("B::boo\n");
	}	
};

int main()
{
	A a;
	B b;
	return 0;
}
