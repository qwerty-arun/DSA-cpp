/* 
- We know that 4+1+2-1-2 will give us 4. What if we apply this in our array?
- We will use BITWISE XOR operator
- Properties: n^0 = n and n^n = 0
- So, 1^1 = 0, 0^1 = 1 and in our case: 4^1^2^1^2 will give us 4 which is exaclty what we want
*/

#include <iostream>
#include <vector>
int main()
{
	std::vector<int> vec = {4,1,2,1,2};
	int ans{};
	for (int val:vec)
		{
		ans = ans^val;
		}
	std::cout<<"Single element: "<< ans<<"\n";
	return 0;
}
