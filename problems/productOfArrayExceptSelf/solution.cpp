#include <iostream>
#include <vector>

int main()
{
  std::vector<int> nums = {1,2,3,4};
  std::vector<int> prefix(4,1);
  std::vector<int> suffix(4,1);
  std::vector<int> ans(4,1);
  for(int i{1};i<nums.size();i++)
    prefix[i] = prefix[i-1] * nums[i-1];

  for(int i=nums.size()-2;i>=0;i--)
    suffix[i] = suffix[i+1] * nums[i+1];

  for(int i=1;i<nums.size();i++)
    ans[i] = ans[i-1] * nums[i-1];

  int suff =1;
  for(int i=nums.size()-2;i>=0;i--)
  {
    suff *= nums[i+1];
    ans[i]*= suff;
  }

  for(int i=0;i<nums.size();i++)
    std::cout<<ans[i]<<" ";
  return 0;
}
