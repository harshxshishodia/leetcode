class Solution {
public:
    int longestPalindromicSubsequence(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        if (n == 1) {
            return 1;
        }

        vector<vector<int>> older(
            n + 1,
            vector<int>(
                k + 1
            )
        );

        vector<vector<int>> previous(
            n,
            vector<int>(
                k + 1,
                1
            )
        );

        for (int length = 2;
             length <= n;
             length++) {
            int count =
                n -
                length +
                1;

            vector<vector<int>> current(
                count,
                vector<int>(
                    k + 1
                )
            );

            for (int left = 0;
                 left < count;
                 left++) {
                int right =
                    left +
                    length -
                    1;

                int difference =
                    abs(
                        s[left] -
                        s[right]
                    );

                int cost = min(
                    difference,
                    26 -
                    difference
                );

                for (int budget = 0;
                     budget <= k;
                     budget++) {
                    current[left][budget] = max(
                        previous[left][budget],
                        previous[left + 1][budget]
                    );

                    if (cost <= budget) {
                        current[left][budget] = max(
                            current[left][budget],
                            2 +
                            older[left + 1][budget - cost]
                        );
                    }
                }
            }

            older =
                previous;

            previous =
                current;
        }

        return previous[0][k];
    }
};
