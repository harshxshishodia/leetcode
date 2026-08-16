class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1000000007;

        if (n == 0) {
            return 1;
        }

        vector<long long> dp(n + 1);
        dp[0] = 1;

        if (n >= 1) {
            dp[1] = 0;
        }

        for (int value = 2; value <= n; value++) {
            dp[value] =
                1LL *
                (value - 1) *
                (dp[value - 1] + dp[value - 2]) %
                MOD;
        }

        return static_cast<int>(dp[n]);
    }
};
