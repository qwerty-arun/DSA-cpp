
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& ans, int i,vector<vector<int>> &allSubsets)
{
  if(i == arr.size()) //Base Case
  {
    allSubsets.push_back({ans});
    for(int val:ans)
    {
      cout<<val<<" ";
    }
    cout<<"\n";
    return;
  }
  ans.push_back(arr[i]); //include
  printSubsets(arr, ans, i+1, allSubsets); //include
  ans.pop_back(); //backtracking
  int index = i+1;

  while(index<arr.size() && arr[index]==arr[index-1]) //skip duplicate elements
  {
    index++;
  }
  //exclude
    printSubsets(arr, ans, index, allSubsets);
}

int main()
{
  vector<int> arr ={1,2,2};
  sort(arr.begin(),arr.end());
  vector<int> ans;
  vector<vector<int>> allSubsets;
    printSubsets(arr, ans, 0,allSubsets);
}
