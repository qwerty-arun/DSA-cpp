#include <algorithm>
#include <cmath>
# include <iostream>
#include <vector>

int singleElement(std::vector<int> vec, int size)
{
	int st{0}, end = size-1,mid{0};
	while(st<=end)
	{
		mid = st + (end-st)/2;
		if(mid ==0 && vec[0]!=vec[1]) //corner case to handle vec[-1] != vec[0]
			return vec[mid];
		if(mid==size-1 && vec[size-2]!=vec[size-1])
			return vec[mid];

		if(vec[mid-1]!=vec[mid] and vec[mid]!=vec[mid+1])
			return vec[mid];
		if(mid%2==0) //even
		{
			if(vec[mid-1]==vec[mid])
				end = mid-1;
			else
				st=mid+1;
		}
		else //odd
		{
			if(vec[mid-1]==vec[mid])
				st=mid+1;
			else
				end = mid-1;
		}
	}
	return -1; //fail
}
int main()
{
	std::vector<int> vec = {1,1,2,3,3,4,4,8,8};
	std::cout<<"Single Element: "<<singleElement(vec,vec.size());
	return 0;
}
