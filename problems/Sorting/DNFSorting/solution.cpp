#include <iostream>
#include <utility>
#include <vector>

int main()
{
	std::vector<int> vec = {2,0,2,1,1,0,1,2,0,0};
	int mid{0},high=vec.size()-1,low=0;
	while(mid<=high)
	{
		if(vec[mid]==0)
		{
			std::swap(vec[low],vec[mid]);
			mid++;
			low++;
		}
		else if(vec[mid]==1)
		{
			mid++;
		}
		else
		{
			std::swap(vec[high],vec[mid]);
			high--;

		}
	}
	for(int i:vec)
		std::cout<<i<<" ";
	return 0;
}
