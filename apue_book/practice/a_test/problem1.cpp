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
	DerivedStruct s;
	return s.i;
}
