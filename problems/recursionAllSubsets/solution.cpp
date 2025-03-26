// Time complexity: O(2^n *n)
#include <iostream>
#include <vector>

void printSubsets(std::vector<int> &arr, std::vector<int> &ans, int i)
{
   if(i == arr.size())
    {
    for(int val:ans)
      std::cout<<val<<" ";
    std::cout<<"\n";
    return;
    }
  ans.push_back(arr[i]);
  printSubsets(arr, ans, i+1);

  ans.pop_back();
  printSubsets(arr, ans, i+1);
}

int main()
{
  std::vector<int> arr = {1,2,3};
  std::vector<int> ans;
  printSubsets(arr, ans, 0);
  return 0;
}
