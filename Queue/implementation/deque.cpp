#include <cstdlib>
#include <iostream>
#include <deque>

using namespace std;


int main()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(7);
	d.push_front(8);

	while(!d.empty())
	{
		cout<<d.front()<<" ";
		d.pop_front();
	}
	cout<<endl;
	return 0;
}
