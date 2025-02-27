// Brute Force: Linear Search
// Optimized: Sort the array and then return last element of the array
// Most optimized: Use Binary Search
# include <iostream>
#include <vector>

int peak(std::vector<int> vec, int size)
{
	int st{1},end = vec.size()-1,mid{0};
	while(st<=end)
	{
		mid = st + (end-st)/2;
		if(vec[mid-1]<vec[mid] && vec[mid]>vec[mid+1])
			return mid;
		if(vec[mid-1]<vec[mid])
			st = mid+1;
		else
			end = mid-1;
	}
	return mid;
}
int main()
{
	std::vector<int> vec = {0,3,8,9,5,2};
	std::cout<<"Peak Index is: "<<peak(vec,vec.size());
	return 0;
}
