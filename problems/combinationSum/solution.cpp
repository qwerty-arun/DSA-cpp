#include <iostream>
#include <vector>
#include <set>

std::set<std::vector<int>> s;
void getAllCombinations(std::vector<int>& arr, int idx, int target, std::vector<std::vector<int>>&ans, std::vector<int>& combin)
{

	if(idx == arr.size() || target<0)
		return;
	if(target==0)
	{
		if(s.find(combin) == s.end())
		{
			ans.push_back({combin});
			s.insert(combin);
		}
		return;
	}

	combin.push_back(arr[idx]);
	//single choice
	getAllCombinations(arr, idx+1, target-arr[idx], ans, combin);

	//multiple choice
	getAllCombinations(arr, idx, target-arr[idx], ans, combin);

	//exclusion
	combin.pop_back();
	getAllCombinations(arr, idx+1, target, ans, combin);

}

int main()
{
	std::vector<std::vector<int>>ans;
	std::vector<int> combin;
	std::vector<int> arr{2,3,5};
	int target = 8;
	getAllCombinations(arr, 0, target, ans, combin);

	for(int i = 0;i<ans.size();i++)
	{
     		std::vector vec = ans[i];
		for(int j =0; j<vec.size();j++)
		{
			std::cout<<vec[j]<<" ";
		}
		std::cout<<"\n";
	}
}
