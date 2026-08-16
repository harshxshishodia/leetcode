class Solution {
public:
    int minimumSubstringsInPartition(
        string s
    ) {
        int n =
            static_cast<int>(
                s.size()
            );

        vector<int> dp(
            n + 1,
            n + 1
        );

        dp[0] = 0;

        for (int left = 0;
             left < n;
             left++) {
            if (dp[left] > n) {
                continue;
            }

            array<int, 26> frequency = {};

            int maximum = 0;
            int distinct = 0;

            for (int right = left;
                 right < n;
                 right++) {
                int character =
                    s[right] -
                    'a';

                if (frequency[character] == 0) {
                    distinct++;
                }

                frequency[character]++;

                maximum = max(
                    maximum,
                    frequency[character]
                );

                int length =
                    right -
                    left +
                    1;

                if (
                    maximum *
                    distinct ==
                    length
                ) {
                    dp[right + 1] = min(
                        dp[right + 1],
                        dp[left] +
                        1
                    );
                }
            }
        }

        return dp[n];
    }
};
