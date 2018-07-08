// Runtime result is below.
// 	constructing Base0xfdfc20
//	constructing Derived0xfdfc20
//	destroying Base0xfdfc20
//	NOTE: There is no deconstruct for Derived class here. 
#include <iostream>

class Base {
public:
	Base()
	{
		std::cerr << "constructing Base" << this << std::endl;
		i = new int;
	}
	~Base()
	{
		std::cerr << "destroying Base" << this << std::endl;
	}
private:
	int* i;
};

class Derived:public Base
{
public:
	Derived()
	{
		std::cerr << "constructing Derived" << this << std::endl;
		d = new double;
	}
	~Derived()
	{
		std::cerr << "destroying Derived" << this << std::endl;
		delete d;
	}
private:
	double* d;
};

int main(int argc, char** argv)
{
	using namespace std;
	int ret = 1;
	Base* thePtr = new Derived;
	delete thePtr;
	return ret;
}
