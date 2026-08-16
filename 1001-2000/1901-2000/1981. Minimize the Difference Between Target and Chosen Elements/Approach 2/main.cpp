class Solution {
    vector<vector<int>> memo;

    int solve(
        const vector<vector<int>>& mat,
        int target,
        int row,
        int sum
    ) {
        if (row == static_cast<int>(mat.size())) {
            return abs(
                sum - target
            );
        }

        if (memo[row][sum] != -1) {
            return memo[row][sum];
        }

        int answer =
            numeric_limits<int>::max();

        for (int value : mat[row]) {
            answer = min(
                answer,
                solve(
                    mat,
                    target,
                    row + 1,
                    sum + value
                )
            );
        }

        memo[row][sum] =
            answer;

        return memo[row][sum];
    }

public:
    int minimizeTheDifference(
        vector<vector<int>>& mat,
        int target
    ) {
        int maximumSum = 0;

        for (const vector<int>& row : mat) {
            maximumSum +=
                *max_element(
                    row.begin(),
                    row.end()
                );
        }

        memo.assign(
            mat.size(),
            vector<int>(
                maximumSum + 1,
                -1
            )
        );

        return solve(
            mat,
            target,
            0,
            0
        );
    }
};
