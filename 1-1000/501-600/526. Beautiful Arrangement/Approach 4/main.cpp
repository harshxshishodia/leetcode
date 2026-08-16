class Solution {
public:
    int countArrangement(int n) {
        int states = 1 << n;
        vector<int> dp(states);
        dp[0] = 1;

        for (int mask = 0; mask < states; mask++) {
            int position = __builtin_popcount(
                static_cast<unsigned int>(mask)
            ) + 1;

            for (int value = 1; value <= n; value++) {
                int bit = 1 << (value - 1);

                if ((mask & bit) != 0) {
                    continue;
                }

                if (value % position != 0 &&
                    position % value != 0) {
                    continue;
                }

                dp[mask | bit] += dp[mask];
            }
        }

        return dp[states - 1];
    }
};
