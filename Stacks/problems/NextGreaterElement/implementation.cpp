//We are using reverse approach, instead of traversing from front, we do it from back.
//Starting with last element which has no greater element, then all the way to first element
//We will be using stacks for this, the last element which will be inserted will be on the top, which can be the immediate greater element
//
//TC: O(n)
//SC: O(n)
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
    vector<int>arr = {6, 8, 0, 1, 3};
    stack<int> s;
    vector<int> ans(arr.size(),0);
    for(int i = arr.size()-1;i>=0;i--)
    {
        while(s.size()>0 && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(arr[i]);
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
