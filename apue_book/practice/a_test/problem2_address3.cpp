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
		printf("A::A()\n");	
	}
	virtual ~A()
	{
		printf("~A::A()\n");	
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
		printf("B::B()\n");	
	}
	virtual ~B()
	{
		printf("~B::B()\n");
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
	a.foo();
	a.boo();
	
	printf("main(). Before \"B b;\" \n");
	B b;
	printf("main(). Address of b = %p\n", &b);
	b.foo();
	b.boo();

	printf("main(). Before \"return 0;\" \n");
	return 0;
}
/*
A::A()
A::foo. Address of this = 0x7ffe64507c60
main(). Address of a = 0x7ffe64507c60
A::foo. Address of this = 0x7ffe64507c60
A::boo. Address of this = 0x7ffe64507c60
main(). Before "B b;" 
A::A()
A::foo. Address of this = 0x7ffe64507c70
B::B()
B::foo. Address of this = 0x7ffe64507c70
main(). Address of b = 0x7ffe64507c70
B::foo. Address of this = 0x7ffe64507c70
B::boo. Address of this = 0x7ffe64507c70
main(). Before "return 0;" 
~B::B()
B::boo. Address of this = 0x7ffe64507c70
~A::A()
A::boo. Address of this = 0x7ffe64507c70
~A::A()
A::boo. Address of this = 0x7ffe64507c60
*/
