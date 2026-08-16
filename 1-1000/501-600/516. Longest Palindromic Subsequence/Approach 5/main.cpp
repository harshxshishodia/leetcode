class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = static_cast<int>(s.size());
        vector<int> dp(n);

        for (int left = n - 1; left >= 0; left--) {
            int diagonal = 0;
            dp[left] = 1;

            for (int right = left + 1; right < n; right++) {
                int previous = dp[right];

                if (s[left] == s[right]) {
                    dp[right] = 2 + diagonal;
                } else {
                    dp[right] = max(
                        dp[right],
                        dp[right - 1]
                    );
                }

                diagonal = previous;
            }
        }

        return dp[n - 1];
    }
};
