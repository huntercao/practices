// Need compile with: $ gcc ./problem2.cpp -lstdc++
// To avoid below error:
//	/tmp/ccGMKhSa.o: In function `A::~A()':
//	problem2.cpp:(.text._ZN1AD2Ev[_ZN1AD5Ev]+0x35): undefined reference to `operator delete(void*)'

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
		printf("A::foo. Address of this = %p\n", this);
	}
	virtual void boo()
	{
		printf("A::boo. Address of this = %p\n", this);
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
		printf("B::foo. Address of this = %p\n", this);
	}
	virtual void boo()
	{
		printf("B::boo. Address of this = %p\n", this);
	}	
};

int main()
{
	A a;
	printf("main(). Address of a = %p\n", &a);
	B b;
	printf("main(). Address of b = %p\n", &b);
	return 0;
}
