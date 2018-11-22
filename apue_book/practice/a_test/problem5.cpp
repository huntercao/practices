#include <iostream>

class Base {
public:
	Base()
	{
		std::cerr << "constructing Base " << this << std::endl;
		i = new int;
	}
	virtual	~Base()
	{
		std::cerr << "destroying Base " << this << std::endl;
	}
private:
	int* i;
};

class Derived:public Base
{
public:
	Derived()
	{
		std::cerr << "constructing Derived " << this << std::endl;
		d = new double;
	}
	virtual ~Derived()
	{
		std::cerr << "destroying Derived " << this << std::endl;
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
/*
constructing Base 0xcf4c20
constructing Derived 0xcf4c20
destroying Derived 0xcf4c20
destroying Base 0xcf4c20
*/
