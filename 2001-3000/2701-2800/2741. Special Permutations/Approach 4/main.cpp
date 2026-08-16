class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(nums.size());

        int states =
            1 << n;

        vector<vector<int>> dp(
            states,
            vector<int>(n)
        );

        for (int index = 0;
             index < n;
             index++) {
            dp[1 << index][index] =
                1;
        }

        for (int mask = 1;
             mask < states;
             mask++) {
            for (int last = 0;
                 last < n;
                 last++) {
                if (dp[mask][last] == 0) {
                    continue;
                }

                for (int next = 0;
                     next < n;
                     next++) {
                    if ((mask & (1 << next)) != 0) {
                        continue;
                    }

                    if (nums[last] % nums[next] != 0 &&
                        nums[next] % nums[last] != 0) {
                        continue;
                    }

                    int nextMask =
                        mask |
                        (1 << next);

                    dp[nextMask][next] =
                        (
                            dp[nextMask][next] +
                            dp[mask][last]
                        ) %
                        MOD;
                }
            }
        }

        long long answer = 0;

        for (int last = 0;
             last < n;
             last++) {
            answer +=
                dp[states - 1][last];

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
