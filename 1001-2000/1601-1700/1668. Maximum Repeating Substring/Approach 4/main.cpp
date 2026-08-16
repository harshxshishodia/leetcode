class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = static_cast<int>(sequence.size());
        int m = static_cast<int>(word.size());
        vector<int> dp(n + 1);
        int answer = 0;

        for (int end = m; end <= n; end++) {
            if (sequence.compare(end - m, m, word) == 0) {
                dp[end] = dp[end - m] + 1;
                answer = max(answer, dp[end]);
            }
        }

        return answer;
    }
};
