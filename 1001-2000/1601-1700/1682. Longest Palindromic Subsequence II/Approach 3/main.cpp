class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n =
            static_cast<int>(s.size());

        if (n < 2) {
            return 0;
        }

        vector<vector<array<int, 27>>> dp(
            n,
            vector<array<int, 27>>(
                n
            )
        );

        for (int left = 0; left < n; left++) {
            for (int right = 0; right < n; right++) {
                dp[left][right].fill(0);
            }
        }

        for (int length = 2;
             length <= n;
             length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left + length - 1;

                for (int previous = 0;
                     previous <= 26;
                     previous++) {
                    int answer = max(
                        dp[left + 1][right][previous],
                        dp[left][right - 1][previous]
                    );

                    int current =
                        s[left] - 'a';

                    if (s[left] == s[right] &&
                        current != previous) {
                        int inside =
                            length == 2
                                ? 0
                                : dp[left + 1][right - 1][current];

                        answer = max(
                            answer,
                            2 + inside
                        );
                    }

                    dp[left][right][previous] =
                        answer;
                }
            }
        }

        return dp[0][n - 1][26];
    }
};
