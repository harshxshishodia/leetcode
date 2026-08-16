class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) {
            swap(word1, word2);
        }

        int firstLength = static_cast<int>(word1.size());
        int secondLength = static_cast<int>(word2.size());

        vector<int> dp(secondLength + 1);

        for (int i = 1; i <= firstLength; i++) {
            int diagonal = 0;

            for (int j = 1; j <= secondLength; j++) {
                int previous = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = diagonal + 1;
                } else {
                    dp[j] = max(
                        dp[j],
                        dp[j - 1]
                    );
                }

                diagonal = previous;
            }
        }

        return
            firstLength +
            secondLength -
            2 * dp[secondLength];
    }
};
