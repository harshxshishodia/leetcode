class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = static_cast<int>(s.size());

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                n + 1
            )
        );

        int answer = 0;

        for (int first = n - 1;
             first >= 0;
             first--) {
            for (int second = n - 1;
                 second > first;
                 second--) {
                if (s[first] == s[second]) {
                    dp[first][second] =
                        1 +
                        dp[first + 1][second + 1];

                    answer = max(
                        answer,
                        dp[first][second]
                    );
                }
            }
        }

        return answer;
    }
};
