//TC: O(n)
//SC: O(n)
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
    vector<int>price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for(int i = 0;i<price.size();i++) //Even though the TC looks like its O(n^2), its actually O(n) becoz the pop and push operations for each element happens only once
    {
        while(s.size()>0 && price[s.top()] < price[i])
            s.pop();

        if(s.empty())
        {
            ans[i] = i+1;
        }
        else
            ans[i] = i-s.top(); //i-prevHigh

        s.push(i);
    }

    //print ans vals
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}
