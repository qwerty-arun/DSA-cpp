/*
- We definitely need 2 loops for this
- The algorithm works becoz allotment is in contiguous order
- min = 0 to 10
- We need to find ans in this range
- Apply binary search for this array
- 0	1	2	3	4	5	6	7	8	9	10
- st					mid					end
- Check if mid is valid or invalid: If valid, then go left else right
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool isValid(std::vector<int> arr,int n, int m, int maxAllowedPages)
{
	int stu= 1,pages=0;
	for(int i=0;i<n;i++)
	{
		if(pages+arr[i]<=maxAllowedPages)
			pages+=arr[i];
		else
		{
			stu++;
			pages = arr[i];
		}
	}
	return stu>m?false:true;
}
int main()
{
	std::vector<int> arr = {2,1,3,4};
	int st{0},end,ans=-1,mid,n{4},m{2};
	for(int i:arr)
		end+=i;
	while(st<=end)
	{
		mid = st + (end-st)/2;
		if(isValid(arr,n,m,mid)) //valid so, search in left
		{
			ans = mid;
			end= mid-1; 
		}
		else
		{
			st = mid +1; //right
		}
	}
	std::cout<<"Min of the max pages that a student gets is: "<<mid;
	return 0;
}
