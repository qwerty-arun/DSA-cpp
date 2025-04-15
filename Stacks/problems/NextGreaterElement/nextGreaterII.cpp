//TC: O(n)
//SC: O(n)
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
    vector<int>arr = {1,2,3,4,3};
    stack<int> s;
    int n = arr.size();
    vector<int> ans(n,-1);

    for(int i = 2*n-1;i>=0;i--)
    {
        while(s.size()>0 && arr[s.top()] <= arr[i%n])
        {
            s.pop();
        }
        ans[i%n] = s.empty() ? -1 : arr[s.top()];
        s.push(i%n);
    }

    cout<<"The array: \n";
    for(int val:arr)
        cout<<val<<" ";
    cout<<"\n";
    cout<<"The next greater elements: \n";
    for(int val:ans)
        cout<<val<<" ";
    cout<<"\n";
    return 0;
}
