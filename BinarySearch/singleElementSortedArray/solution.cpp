#include <algorithm>
#include <cmath>
# include <iostream>
#include <vector>

int singleNonDuplicate(vector<int>& nums) {
int size = nums.size();
int st{0}, end = size-1, mid{0};
while(st<end)
{
	mid = st + (end - st)/2;

        if(mid % 2==1)
        	mid--;
                
        if(nums[mid] == nums[mid+1])
                st = mid + 2;
        else
                end = mid;
}
        return nums[st];
}

int main()
{
	std::vector<int> vec = {1,1,2,3,3,4,4,8,8};
	std::cout<<"Single Element: "<<singleElement(vec,vec.size());
	return 0;
}
