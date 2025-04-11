// Time Complexity: O(n) and Space Complexity: O(n)
#include <iostream>
#include <vector>

bool isSorted(std::vector<int> arr, int n)
{
  if(n==0 || n==1)
    return true;
  else
  return (arr[n-1]>=arr[n-2] && isSorted(arr,n-1));
}

int main()
{
  std::vector<int> arr = {1,2,6,4,5};
  bool ans = isSorted(arr,5); 
  if(ans)
  {
    std::cout<<"Array is Sorted!\n";
  }
  else
    std::cout<<"Array is Not Sorted!\n";
  return 0;
}
