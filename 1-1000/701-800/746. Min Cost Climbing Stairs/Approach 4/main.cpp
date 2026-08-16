class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int previous2 = 0;
        int previous1 = 0;

        for (int i = 2; i <= static_cast<int>(cost.size()); i++) {
            int current = min(
                previous1 + cost[i - 1],
                previous2 + cost[i - 2]
            );

            previous2 = previous1;
            previous1 = current;
        }

        return previous1;
    }
};
