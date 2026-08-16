class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1000000007;

        static const vector<vector<int>> next = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(10)
        );

        for (int digit = 0; digit <= 9; digit++) {
            dp[1][digit] = 1;
        }

        for (int length = 2; length <= n; length++) {
            for (int digit = 0; digit <= 9; digit++) {
                for (int nextDigit : next[digit]) {
                    dp[length][nextDigit] +=
                        dp[length - 1][digit];

                    dp[length][nextDigit] %= MOD;
                }
            }
        }

        long long answer = 0;

        for (int digit = 0; digit <= 9; digit++) {
            answer += dp[n][digit];
            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
