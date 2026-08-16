class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }

        if (n == 1) {
            return k;
        }

        vector<long long> dp(n + 1);
        dp[1] = k;
        dp[2] = 1LL * k * k;

        for (int posts = 3; posts <= n; posts++) {
            dp[posts] = 1LL * (k - 1) *
                        (dp[posts - 1] + dp[posts - 2]);
        }

        return static_cast<int>(dp[n]);
    }
};
