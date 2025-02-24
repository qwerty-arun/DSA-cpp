/* 
- The brute force approach will be to check every pair by using two loops and then return indices with vector
- Notice that this approach doesn't use an important property given in the question. The array is SORTED.
- Now the optimal approach will use two pointers from start to end, check their sum, if small, then start++ else end--
*/

#include <iostream>
#include <vector>

void pairSum(std::vector<int> vec, int size, int target) {
    int i = 0, j = size - 1;
    bool found = false; // To track if we found at least one pair

    while (i < j) {
        int pair_sum = vec[i] + vec[j];

        if (pair_sum > target) {
            j--; // Decrease end pointer
        } 
        else if (pair_sum < target) {
            i++; // Increase start pointer
        } 
        else {
            std::cout << "The indices of the pair are: " << i << " " << j << "\n";
            found = true;
            i++;  // Move forward to check for other pairs
            j--;  // Move backward to check for other pairs
        }
    }

    if (!found) {
        std::cout << "There is no pair which has the sum: " << target << "\n";
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int target = 3;
    pairSum(vec, vec.size(), target);
}

