// This program will have the runtime error below:
// 	Segmentation fault (core dumped)	
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
		if(*vi == 1)
		{
			theVector.erase(vi);
		}
	}
	return ret;
}	
