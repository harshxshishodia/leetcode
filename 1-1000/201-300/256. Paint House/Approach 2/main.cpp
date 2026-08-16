class Solution {
    int solve(
        const vector<vector<int>>& costs,
        int house,
        int previousColor,
        vector<vector<int>>& memo
    ) {
        if (house == static_cast<int>(costs.size())) {
            return 0;
        }

        int state = previousColor + 1;

        if (memo[house][state] != -1) {
            return memo[house][state];
        }

        int answer = numeric_limits<int>::max();

        for (int color = 0; color < 3; color++) {
            if (color == previousColor) {
                continue;
            }

            answer = min(
                answer,
                costs[house][color] +
                solve(costs, house + 1, color, memo)
            );
        }

        memo[house][state] = answer;
        return memo[house][state];
    }

public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> memo(
            costs.size(),
            vector<int>(4, -1)
        );

        return solve(costs, 0, -1, memo);
    }
};
