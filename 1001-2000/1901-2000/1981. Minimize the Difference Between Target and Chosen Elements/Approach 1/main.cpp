class Solution {
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

        return answer;
    }

public:
    int minimizeTheDifference(
        vector<vector<int>>& mat,
        int target
    ) {
        return solve(
            mat,
            target,
            0,
            0
        );
    }
};
