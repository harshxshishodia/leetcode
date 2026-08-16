class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1);

        for (int value = 2; value <= n; value++) {
            for (int divisor = 1; divisor < value; divisor++) {
                if (value % divisor == 0 && !dp[value - divisor]) {
                    dp[value] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
