#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> previousSmallerElement(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(a[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 1, 0, 8, 6};
    vector<int> result = previousSmallerElement(arr);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
