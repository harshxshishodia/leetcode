class Solution {
public:
    int countHousePlacements(int n) {
        const long long MOD =
            1000000007;

        vector<array<long long, 2>> dp(
            n + 1
        );

        dp[0][0] = 1;
        dp[0][1] = 0;

        for (int plots = 1;
             plots <= n;
             plots++) {
            dp[plots][0] =
                (
                    dp[plots - 1][0] +
                    dp[plots - 1][1]
                ) %
                MOD;

            dp[plots][1] =
                dp[plots - 1][0];
        }

        long long oneSide =
            (
                dp[n][0] +
                dp[n][1]
            ) %
            MOD;

        return static_cast<int>(
            oneSide *
            oneSide %
            MOD
        );
    }
};
