class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int row = 1; row < m; row++) {
            for (int column = 1; column < n; column++)
                dp[column] += dp[column - 1];
        }

        return dp[n - 1];
    }
};