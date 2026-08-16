class Solution {
public:
    int minimumPartition(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[n] = 0;

        for (int index = n - 1;
             index >= 0;
             index--) {
            long long value = 0;

            for (int end = index;
                 end < n;
                 end++) {
                value =
                    value *
                    10 +
                    (
                        s[end] -
                        '0'
                    );

                if (value > k) {
                    break;
                }

                if (dp[end + 1] != INF) {
                    dp[index] = min(
                        dp[index],
                        1 +
                        dp[end + 1]
                    );
                }
            }
        }

        return dp[0] == INF
            ? -1
            : dp[0];
    }
};
