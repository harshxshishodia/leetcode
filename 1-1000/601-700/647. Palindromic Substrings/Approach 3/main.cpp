class Solution {
public:
    int countSubstrings(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<bool>> dp(
            n,
            vector<bool>(n)
        );

        int answer = 0;

        for (int length = 1; length <= n; length++) {
            for (int left = 0; left + length <= n; left++) {
                int right = left + length - 1;

                if (s[left] == s[right] &&
                    (length <= 2 || dp[left + 1][right - 1])) {
                    dp[left][right] = true;
                    answer++;
                }
            }
        }

        return answer;
    }
};
