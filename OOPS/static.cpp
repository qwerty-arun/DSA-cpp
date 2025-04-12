// C++ program to calculate the area of a square and a circle

#include <iostream>
using namespace std;

class ABC
{
public:
	ABC()
	{
		cout<<"Constructor\n";
	}
	~ABC()
	{
		cout<<"Deconstructor\n";
	}
};
int main()
{
	if(true)
	{
		static ABC obj;
	}
	cout<<"End of main\n";
	return 0;
}
