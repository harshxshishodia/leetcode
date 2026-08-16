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
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, -1));
        vector<int> row;

        for (int col = 0; col <= rowIndex; col++) {
            row.push_back(solve(rowIndex, col, dp));
        }

        return row;
    }
};
