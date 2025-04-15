#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

std::vector<int> nextGreater(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::unordered_map<int, int> m; //nums2[i], NG
    std::stack<int> s;
    for(int i = nums2.size()-1; i>=0;i--)
    {
        while(s.size()>0 && s.top() <= nums2[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            m[nums2[i]] = -1;
        }
        else
            m[nums2[i]] = s.top();
        s.push(nums2[i]);
    }
    std::vector<int> ans;
    for(int i=0;i<nums1.size();i++)
    {
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}
using namespace std;
int main() {

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = nextGreater(nums1, nums2);

    cout<<"The next greater elements: \n";
    for(int val:ans)
        cout<<val<<" ";
    cout<<"\n";
    return 0;
}
