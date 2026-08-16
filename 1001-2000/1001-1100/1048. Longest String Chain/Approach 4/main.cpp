class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(
            words.begin(),
            words.end(),
            [](const string& first, const string& second) {
                return first.size() < second.size();
            }
        );

        unordered_map<string, int> dp;
        int answer = 0;

        for (const string& word : words) {
            int best = 1;

            for (int removed = 0;
                 removed < static_cast<int>(word.size());
                 removed++) {
                string previous =
                    word.substr(
                        0,
                        removed
                    ) +
                    word.substr(
                        removed + 1
                    );

                best = max(
                    best,
                    dp[previous] + 1
                );
            }

            dp[word] = max(
                dp[word],
                best
            );

            answer = max(
                answer,
                dp[word]
            );
        }

        return answer;
    }
};
