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
