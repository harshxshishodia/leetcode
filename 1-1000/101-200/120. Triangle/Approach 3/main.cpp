class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = static_cast<int>(triangle.size());
        vector<vector<int>> dp = triangle;

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] += min(
                    dp[row + 1][col],
                    dp[row + 1][col + 1]
                );
            }
        }

        return dp[0][0];
    }
};
