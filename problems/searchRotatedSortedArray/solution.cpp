#include <iostream>
#include <vector>

int search(std::vector<int> arr, int size, int target)
{
	int st{0},end=size-1,mid{0};
	while(st<=end)
	{
		mid = st + (end-st)/2;
		if(arr[mid] == target)
			return mid;
		if(arr[st]<=arr[mid])
		{
			if(arr[st] <= target && target<= arr[mid])
				end = mid-1;
			else
				st = mid+1;
		}
		else
		{
			if(arr[mid]<=target && target <=arr[end])
				st= mid +1;
			else
				end = mid -1;
		}
	}
	return mid;
}
int main()
{
	std::vector<int> arr = {3,4,5,6,7,0,1,2};
	std::cout<<search(arr, arr.size(),5);
	return 0;
}
