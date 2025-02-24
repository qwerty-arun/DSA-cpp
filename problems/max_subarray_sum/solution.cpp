/* 
- We have a function just to print out all the subarrays
- We can optimize the code to O(n^2)
- the most optimized is the Kadane's algorithm : O(n)
- The idea is that '+' + '+' will be + and that small '-' and  big '+' will give us '+' and 'small +' + 'big -' will give -ve number
- When the last case happens, reset the sum to zero since, it is negative, we don't want that in our answer
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

void print_subarrays(std::vector <int> vec, int size)
{
	std::cout<<"All the subarrays: "<<'\n';
	for(int st{};st<vec.size();st++)
	{
		for(int end{st};end<vec.size();end++)
		{
			std::cout<<"{";
			for(int i = st;i<=end;i++)
				std::cout<<vec[i]<<" ";
		std::cout<<"} , ";
		}
     std::cout<<'\n';
	}
}
void optimal(std::vector<int> vec, int size)
{
	int current_sum{0},max_sum{0};
	for(int st{};st<vec.size();st++)
	{
		current_sum = 0;
		for(int end{st};end<vec.size();end++)
		{
			current_sum+=vec[end];
			max_sum = std::max(current_sum,max_sum);
		}
	}
	std::cout << "Max subarray: "<<max_sum<<"\n";

}

void optimized(std::vector<int>vec, int size)
{
	int carrySum{0},maxSum=INT_MIN;
	for(int i{};i<vec.size();i++)
	{
		carrySum+=vec[i];
		maxSum=std::max(carrySum,maxSum);
		if(carrySum<maxSum)
			carrySum=0;
	}
	std::cout << "Max subarray: "<<maxSum<<"\n";
}
int main()
{
	std::vector<int> vec = {1,2,3,4,5};
	optimal(vec,vec.size());
	optimized(vec,vec.size());
	print_subarrays(vec, vec.size());
	return 0;
}
