class Solution {
public:
    long long minIncrementOperations(
        vector<int>& nums,
        int k
    ) {
        const long long INF =
            numeric_limits<long long>::max() /
            4;

        array<long long, 3> dp = {
            0,
            INF,
            INF
        };

        for (int value : nums) {
            array<long long, 3> next = {
                INF,
                INF,
                INF
            };

            long long cost =
                max(
                    0,
                    k -
                    value
                );

            for (int low = 0;
                 low <= 2;
                 low++) {
                if (dp[low] == INF) {
                    continue;
                }

                next[0] = min(
                    next[0],
                    dp[low] +
                    cost
                );

                if (value >= k) {
                    next[0] = min(
                        next[0],
                        dp[low]
                    );
                } else if (low < 2) {
                    next[low + 1] = min(
                        next[low + 1],
                        dp[low]
                    );
                }
            }

            dp =
                next;
        }

        return min({
            dp[0],
            dp[1],
            dp[2]
        });
    }
};
