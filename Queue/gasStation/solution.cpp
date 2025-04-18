#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_gas = std::accumulate(gas.begin(), gas.end(), 0);
        int total_cost = std::accumulate(cost.begin(), cost.end(), 0);

        // First check: If total gas is less than total cost, no solution exists [1, 2].
        if (total_gas < total_cost) {
            return -1;
        }

        int start = 0;
        int current_gas = 0;

        // Iterate through the gas stations [2, 3].
        for (int i = 0; i < gas.size(); ++i) {
            // Calculate the current gas at the current station minus the cost to the next [3, 4].
            current_gas += gas[i] - cost[i];

            // If current gas becomes negative, this starting point is not viable [2, 4].
            if (current_gas < 0) {
                // Move the starting point to the next station [2, 4].
                start = i + 1;
                // Reset the current gas [2, 5].
                current_gas = 0;
            }
        }

        // The final 'start' index is the potential starting station [2, 6].
        return start;
    }
};

int main() {
    Solution solution;
    std::vector<int> gas1 = {1, 2, 3, 4, 5};
    std::vector<int> cost1 = {3, 4, 5, 1, 2};
    std::cout << solution.canCompleteCircuit(gas1, cost1) << std::endl; // Expected output: 3

    std::vector<int> gas2 = {2, 3, 4};
    std::vector<int> cost2 = {3, 4, 3};
    std::cout << solution.canCompleteCircuit(gas2, cost2) << std::endl; // Expected output: -1

    std::vector<int> gas3 = {5, 1, 2, 3, 4};
    std::vector<int> cost3 = {4, 4, 1, 5, 1};
    std::cout << solution.canCompleteCircuit(gas3, cost3) << std::endl; // Expected output: 0

    return 0;
}
