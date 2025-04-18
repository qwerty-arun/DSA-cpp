#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq;
        std::vector<int> result;

        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); ++i) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    std::vector<int> output1 = solution.maxSlidingWindow(nums1, k1);
    std::cout << "Output for nums1: ";
    for (int val : output1) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Expected output: 3 3 5 5 6 7

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> output2 = solution.maxSlidingWindow(nums2, k2);
    std::cout << "Output for nums2: ";
    for (int val : output2) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Expected output: 1

    return 0;
}
