/* 
- Bubble sort algo
*/

#include <iostream>
#include <utility>
#include <vector>
void bubble_sort(std::vector<int> &vec, int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(vec[j]>vec[j+1])
				std::swap(vec[j],vec[j+1]);
		}
	}
}
int main()
{
	std::vector<int> vec = {4,1,2,1,2};
	bubble_sort(vec, vec.size());
	for(int i:vec)
	{
		std::cout<<i<<" ";
	}
	return 0;
}
