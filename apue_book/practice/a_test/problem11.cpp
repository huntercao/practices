/* Compile: gcc -g problem11.cpp -lstdc++Compile error belowoCompile error below:Compile error belowoCompile error below: 
problem11.cpp: In function ‘int main()’:
problem11.cpp:22:6: error: ‘int BaseClass::i’ is private
  int i;
      ^
problem11.cpp:34:11: error: within this context
  return s.i;
           ^
*/
struct BaseStruct
{
	int i;
};

struct DerivedStruct : BaseStruct
{
	DerivedStruct() {};
};

class BaseClass
{
	int i;
};

class	DerivedClass : BaseClass
{
public:
	DerivedClass() {};
}; 

int main()
{
	DerivedClass s;
	return s.i;
}
