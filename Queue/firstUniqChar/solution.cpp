#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

//TC: O(n) and SC: O(n)
class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> m;
        std::queue<int> q;

        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            m[s[i]]++;

            while(q.size()>0 && m[s[q.front()]]>1)
            {
                q.pop();
            }
        }
        return q.empty() ? -1:q.front();
    }
};

int main() {
    Solution solution;
    std::string s1 = "loveleetcode";
    std::cout << solution.firstUniqChar(s1) << std::endl; // Output: 2

    std::string s2 = "aabb";
    std::cout << solution.firstUniqChar(s2) << std::endl; // Output: -1

    std::string s3 = "leetcode";
    std::cout << solution.firstUniqChar(s3) << std::endl; // Output: 0

    return 0;
}
