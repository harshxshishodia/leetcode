class Solution {
    int solve(vector<int>& cost, int index) {
        if (index >= static_cast<int>(cost.size())) {
            return 0;
        }

        return cost[index] + min(solve(cost, index + 1), solve(cost, index + 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost, 0), solve(cost, 1));
    }
};
