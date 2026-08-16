class Solution {
    int solve(
        const vector<int>& values,
        int left,
        int right,
        vector<vector<int>>& memo
    ) {
        if (right - left < 2) {
            return 0;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int answer =
            numeric_limits<int>::max();

        for (int middle = left + 1;
             middle < right;
             middle++) {
            answer = min(
                answer,
                values[left] *
                values[middle] *
                values[right] +
                solve(
                    values,
                    left,
                    middle,
                    memo
                ) +
                solve(
                    values,
                    middle,
                    right,
                    memo
                )
            );
        }

        memo[left][right] = answer;
        return memo[left][right];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = static_cast<int>(values.size());

        vector<vector<int>> memo(
            n,
            vector<int>(n, -1)
        );

        return solve(
            values,
            0,
            n - 1,
            memo
        );
    }
};
