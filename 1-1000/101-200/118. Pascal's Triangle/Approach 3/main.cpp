class Solution {
    int solve(int row, int col, vector<vector<int>>& dp) {
        if (col == 0 || col == row) {
            return 1;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        dp[row][col] = solve(row - 1, col - 1, dp) + solve(row - 1, col, dp);
        return dp[row][col];
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>(numRows, -1));
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            vector<int> current;

            for (int col = 0; col <= row; col++) {
                current.push_back(solve(row, col, dp));
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};
