//Time Complexity: O(logn)
//Space Complexity: O(logn)
#include <algorithm>
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int tar, int st, int end)
{
  int mid;
  if(st<=end)
  {
    mid = st + (end - st)/2;
    if(arr[mid] == tar)
      return mid;
    if(arr[mid]<tar)
      return binarySearch(arr, tar, mid+1, end);
    if(arr[mid]>tar)
      return binarySearch(arr, tar, mid-1, end);
  }
  return -1;
}

int main()
{
  std::vector<int> arr = {1,2,3,4,5};
  int target = 9;
  int ans = binarySearch(arr, target, 0, 4);
  if(ans == -1)
  {
    std::cout<<"Element not found!\n";
  }
  else
    std::cout<<"Mid value: "<<ans;
  return 0;
}
