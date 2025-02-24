/*
- Condition for Majority element: occrurance > n/2
- Brute force approach O(n^2) will be to check frequency of all elements and see if > n/2
- Optimal O(nlogn): Sort the array, then check frequency
- Moore's voting alogrithm: Traverse through the array: same element-> freq++ and different element-> freq--
- If the majority element doesn't exist, count freq of the ans and then check >n/2 or not
*/

#include <algorithm>
#include <iostream>
#include <vector>


void brute_force(std::vector<int> vec, int size)
{
    int freq{};
    for(int val:vec)
    {
        for(int num:vec)
        {
            if(num==val)
                freq++;
        }
        if(freq>size/2)
        {
            std::cout<<"The Majority Element is: "<<val<<'\n';
            break;
        }
    }
}

void optimal(std::vector<int>vec, int size)
{
    std::sort(vec.begin(),vec.end());
    int freq{1}, ans = vec[0];
    for(int i{1};i<size;i++)
    {
        if(vec[i] == vec[i-1])
            freq++;
        else
        {
            freq=1;ans=vec[i];
        }
        if(freq>size/2)
        {
            std::cout<<"The Majority Element is: "<<ans<<'\n';
            break;
        }
    }
}
void moore_algo(std::vector<int>vec, int size)
{
    int freq{0},ans{0};
    for(int i=0;i<size;i++)
    {
        if(freq==0)
            ans=vec[i];
        if(ans==vec[i])
            freq++;
        else
            freq--;
    }

    std::cout<<"The Majority Element is: "<<ans<<'\n';
}


int main() {
    std::vector<int> vec = {1, 2, 2, 1, 1};
    brute_force(vec,vec.size());
    optimal(vec,vec.size());
    moore_algo(vec,vec.size());
}

