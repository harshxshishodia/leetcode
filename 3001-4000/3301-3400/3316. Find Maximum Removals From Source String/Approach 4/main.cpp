class Solution {
public:
    int maxRemovals(
        string source,
        string pattern,
        vector<int>& targetIndices
    ) {
        int n =
            static_cast<int>(source.size());

        int m =
            static_cast<int>(pattern.size());

        vector<bool> removable(
            n
        );

        for (int index :
             targetIndices) {
            removable[index] =
                true;
        }

        const int NEG =
            -1000000000;

        vector<int> dp(
            m + 1,
            NEG
        );

        dp[0] =
            0;

        for (int index = 0;
             index < n;
             index++) {
            vector<int> next =
                dp;

            if (removable[index]) {
                for (int matched = 0;
                     matched <= m;
                     matched++) {
                    if (dp[matched] != NEG) {
                        next[matched] = max(
                            next[matched],
                            dp[matched] +
                            1
                        );
                    }
                }
            }

            for (int matched = 0;
                 matched < m;
                 matched++) {
                if (
                    dp[matched] != NEG &&
                    source[index] ==
                    pattern[matched]
                ) {
                    next[matched + 1] = max(
                        next[matched + 1],
                        dp[matched]
                    );
                }
            }

            dp.swap(
                next
            );
        }

        return dp[m];
    }
};
