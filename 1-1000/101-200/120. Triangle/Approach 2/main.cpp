class Solution {
    int solve(
        const vector<vector<int>>& triangle,
        int row,
        int col,
        vector<vector<int>>& dp
    ) {
        if (row == static_cast<int>(triangle.size()) - 1) {
            return triangle[row][col];
        }

        if (dp[row][col] != 1000000001) {
            return dp[row][col];
        }

        int down = solve(triangle, row + 1, col, dp);
        int diagonal = solve(triangle, row + 1, col + 1, dp);

        dp[row][col] = triangle[row][col] + min(down, diagonal);
        return dp[row][col];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = static_cast<int>(triangle.size());
        vector<vector<int>> dp(
            n,
            vector<int>(n, 1000000001)
        );

        return solve(triangle, 0, 0, dp);
    }
};
