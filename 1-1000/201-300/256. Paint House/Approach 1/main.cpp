class Solution {
    int solve(
        const vector<vector<int>>& costs,
        int house,
        int previousColor
    ) {
        if (house == static_cast<int>(costs.size())) {
            return 0;
        }

        int answer = numeric_limits<int>::max();

        for (int color = 0; color < 3; color++) {
            if (color == previousColor) {
                continue;
            }

            answer = min(
                answer,
                costs[house][color] +
                solve(costs, house + 1, color)
            );
        }

        return answer;
    }

public:
    int minCost(vector<vector<int>>& costs) {
        return solve(costs, 0, -1);
    }
};
