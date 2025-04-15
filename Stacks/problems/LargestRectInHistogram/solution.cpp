#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    stack<int> s;

    // Calculate Right Smaller Nearest
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top(); // Default to n if no smaller element on the right
        s.push(i);
    }

    // Clear the stack for the next calculation
    while (!s.empty()) {
        s.pop();
    }

    // Calculate Left Smaller Nearest
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int height = heights[i];
        int width = right[i] - left[i] - 1; //width = right - left - 1
        int currentArea = height * width;
        maxArea = max(maxArea, currentArea);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << largestRectangleArea(heights) << endl; // Output: 10
    return 0;
}
