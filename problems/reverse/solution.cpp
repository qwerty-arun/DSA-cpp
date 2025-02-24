/* 
- We will use two pointers: st and end
- st=0 andd end=size-1
- then run a while loop with condition st<end
- use inbuilt function swap()
- increment st and decrement end
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
int main()
{
	std::vector<int> vec = {4,2,7,8,1,2,5};
	std::cout<<"Array: ";
	for(int i:vec)
	{
		std::cout<<i<<" ";
	}
	std::cout<<'\n';
	int start{},end=vec.size()-1;
	while(start<end)
	{
		std::swap(vec[start],vec[end]);
		start++;
		end--;
	}
	std::cout<<"Reversed Array: ";
	for(int i:vec)
	{
		std::cout<<i<<" ";
	}
	std::cout<<'\n';
	return 0;
}
