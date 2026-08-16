class Solution {
public:
    int minimizeConcatenatedLength(
        vector<string>& words
    ) {
        const int INF =
            1000000000;

        vector<vector<int>> dp(
            26,
            vector<int>(
                26,
                INF
            )
        );

        int first =
            words[0].front() -
            'a';

        int last =
            words[0].back() -
            'a';

        dp[first][last] =
            words[0].size();

        for (int index = 1;
             index < static_cast<int>(words.size());
             index++) {
            vector<vector<int>> next(
                26,
                vector<int>(
                    26,
                    INF
                )
            );

            int wordFirst =
                words[index].front() -
                'a';

            int wordLast =
                words[index].back() -
                'a';

            int length =
                words[index].size();

            for (int left = 0; left < 26; left++) {
                for (int right = 0; right < 26; right++) {
                    if (dp[left][right] == INF) {
                        continue;
                    }

                    next[left][wordLast] = min(
                        next[left][wordLast],
                        dp[left][right] +
                        length -
                        (right == wordFirst)
                    );

                    next[wordFirst][right] = min(
                        next[wordFirst][right],
                        dp[left][right] +
                        length -
                        (wordLast == left)
                    );
                }
            }

            dp = next;
        }

        int answer = INF;

        for (const vector<int>& row :
             dp) {
            for (int value :
                 row) {
                answer = min(
                    answer,
                    value
                );
            }
        }

        return answer;
    }
};
