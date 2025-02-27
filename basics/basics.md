# Some Basics before we start into our journey in DSA

- INT_MAX denotes `+infinity`
## Vector
- Header file: <vector>
- Declaring: vector<int> vec;
- Defining: vector<int> vec = {1,2,3}; 
- vector <int> vec(3,0); Three elements and initialize with 0. In this case, it will be {0,0,0}.
- For each loop: for(int i:vec) {}
- Vector functions: size, push_back, pop_back, front, back, at etc.
- vec[i] and vec.at[i] are the same
- Static Allocation is for compile-time and implemented using stack
- Dynamic Allocation is for run-time and implemented using heap
- Vector: Size and capacity (S<=C). Capacity keeps doubling if S==C or if we need to add an extra element when S==C
- void display(vector<int> & nums) {} is an example of pass by reference

## Practical 
- 1s ~ 10^8 operations
- If in a question the condition is n<=10^5, can we write code of O(n^2) complexity? The code will compile but won't get submitted, so it will show TLE (Time limit exceeded) since n^2 = 10^10 > 10^8
- nlogn = 10^5 * log(10^5) < 10^8
- n > 10^8 -> O(logn) or O(1)
- n <= 10^8 -> O(n)
- n <= 10^6 -> O(n*logn)
- n <=10^4 -> O(n^2)
- n<= 500 -> O(n^3)
- n <= 25 -> O(2^n)
- n<=12 -> O(n!)

## Some things to take care of
- for(unsigned int i =5;i>=0;i--){} is an infinite loop. 'i' won't be '-1', it will be a very large no
- mid = (st+end)/2 might result in an overflow for very large indices, so its better to use mid = st + (end-st)/2
## Basic Math Required
- lcm and gcd can be calculated using the <numeric> class
