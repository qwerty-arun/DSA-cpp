//Time Complexity O(n! * n)
//Space Complexity O(n! + n) = O(n!)
#include <iostream>
#include <utility>
#include <vector>
using namespace std;


void getPermutations(vector<int>&nums,int idx, vector<vector<int>>& ans)
{
  if(idx == nums.size())
  {
    ans.push_back({nums});
    for(int val:nums)
      cout<<val<<" ";
    cout<<"\n";
      return;
  }
  for(int i = idx;i<nums.size();i++)
  {
    swap(nums[idx],nums[i]);
    getPermutations(nums, idx+1, ans);
    swap(nums[idx],nums[i]);
  }
}

int main()
{
  vector<int> nums = {1,2,3};
  vector<vector<int>> ans;
  getPermutations(nums, 0, ans);
}
