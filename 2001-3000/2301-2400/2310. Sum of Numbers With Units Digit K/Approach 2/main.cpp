class Solution {
public:
    int minimumNumbers(
        int num,
        int k
    ) {
        if (num == 0) {
            return 0;
        }

        const int INF =
            1000000000;

        vector<int> dp(
            num + 1,
            INF
        );

        dp[0] = 0;

        int first =
            k == 0
                ? 10
                : k;

        for (int sum = 1; sum <= num; sum++) {
            for (int value = first;
                 value <= sum;
                 value += 10) {
                dp[sum] = min(
                    dp[sum],
                    1 +
                    dp[sum - value]
                );
            }
        }

        return dp[num] == INF
            ? -1
            : dp[num];
    }
};
