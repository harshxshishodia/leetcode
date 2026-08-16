class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) {
            swap(word1, word2);
        }

        int firstLength = static_cast<int>(word1.size());
        int secondLength = static_cast<int>(word2.size());
        vector<int> dp(secondLength + 1);

        for (int j = 0; j <= secondLength; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= firstLength; i++) {
            int diagonal = dp[0];
            dp[0] = i;

            for (int j = 1; j <= secondLength; j++) {
                int fromTop = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = diagonal;
                } else {
                    dp[j] = 1 + min({
                        dp[j - 1],
                        fromTop,
                        diagonal
                    });
                }

                diagonal = fromTop;
            }
        }

        return dp[secondLength];
    }
};
