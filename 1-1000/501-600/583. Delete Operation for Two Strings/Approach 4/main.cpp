class Solution {
public:
    int minDistance(string word1, string word2) {
        int firstLength = static_cast<int>(word1.size());
        int secondLength = static_cast<int>(word2.size());

        vector<vector<int>> lcs(
            firstLength + 1,
            vector<int>(secondLength + 1)
        );

        for (int i = 1; i <= firstLength; i++) {
            for (int j = 1; j <= secondLength; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    lcs[i][j] =
                        1 + lcs[i - 1][j - 1];
                } else {
                    lcs[i][j] = max(
                        lcs[i - 1][j],
                        lcs[i][j - 1]
                    );
                }
            }
        }

        return
            firstLength +
            secondLength -
            2 * lcs[firstLength][secondLength];
    }
};
