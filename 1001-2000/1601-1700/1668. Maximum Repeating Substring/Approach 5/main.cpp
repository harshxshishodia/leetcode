class Solution {
    vector<int> prefixFunction(const string& pattern) {
        vector<int> prefix(pattern.size());

        for (int i = 1; i < static_cast<int>(pattern.size()); i++) {
            int j = prefix[i - 1];

            while (j > 0 && pattern[i] != pattern[j]) {
                j = prefix[j - 1];
            }

            if (pattern[i] == pattern[j]) {
                j++;
            }

            prefix[i] = j;
        }

        return prefix;
    }

public:
    int maxRepeating(string sequence, string word) {
        int n = static_cast<int>(sequence.size());
        int m = static_cast<int>(word.size());
        vector<int> prefix = prefixFunction(word);
        vector<bool> starts(n);
        int matched = 0;

        for (int i = 0; i < n; i++) {
            while (matched > 0 && sequence[i] != word[matched]) {
                matched = prefix[matched - 1];
            }

            if (sequence[i] == word[matched]) {
                matched++;
            }

            if (matched == m) {
                starts[i - m + 1] = true;
                matched = prefix[matched - 1];
            }
        }

        vector<int> dp(n);
        int answer = 0;

        for (int start = 0; start + m <= n; start++) {
            if (starts[start]) {
                dp[start] = 1;

                if (start >= m) {
                    dp[start] += dp[start - m];
                }

                answer = max(answer, dp[start]);
            }
        }

        return answer;
    }
};
