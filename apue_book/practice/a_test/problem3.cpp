#include <stdio.h>
#include <vector>

int main(int argc, char** argv)
{
	using namespace std;
	int ret = 0;
	vector<int> theVector;
	theVector.push_back(2);
	theVector.push_back(1);
	vector<int>::iterator vi;
	for(vi=theVector.begin(); vi != theVector.end(); vi++)
	{
		printf("sizeof theVector = %zd\n", theVector.size()); 
		printf("vi value = %d\n", *vi);
		if(*vi == 1)
		{
			theVector.erase(vi);
		}
		if(vi == theVector.end())
		{
			printf(" vi is the end of the vector.\n");
			break;
		}
	}
	return ret;
}	
