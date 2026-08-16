class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1);

        for (int row = 0; row <= rowIndex; row++) {
            dp[row].resize(row + 1, 1);

            for (int col = 1; col < row; col++) {
                dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
            }
        }

        return dp[rowIndex];
    }
};
