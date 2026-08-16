class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        n = min(n, 10);
        vector<long long> dp(1 << 10);
        long long answer = 1;

        for (int first = 1; first <= 9; first++) {
            dp[1 << first] = 1;
        }

        for (int length = 1; length <= n; length++) {
            vector<long long> next(1 << 10);

            for (int mask = 0; mask < (1 << 10); mask++) {
                if (dp[mask] == 0) {
                    continue;
                }

                answer += dp[mask];

                if (length == n) {
                    continue;
                }

                for (int digit = 0; digit <= 9; digit++) {
                    if ((mask & (1 << digit)) == 0) {
                        next[mask | (1 << digit)] += dp[mask];
                    }
                }
            }

            dp = next;
        }

        return static_cast<int>(answer);
    }
};
