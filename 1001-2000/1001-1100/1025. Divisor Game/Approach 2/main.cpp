class Solution {
    bool canWin(int n, vector<int>& dp) {
        if (n == 1) {
            return false;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        for (int divisor = 1; divisor < n; divisor++) {
            if (n % divisor == 0 && !canWin(n - divisor, dp)) {
                return dp[n] = 1;
            }
        }

        return dp[n] = 0;
    }

public:
    bool divisorGame(int n) {
        vector<int> dp(n + 1, -1);
        return canWin(n, dp);
    }
};
