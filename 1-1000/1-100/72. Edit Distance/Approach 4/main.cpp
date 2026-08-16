class Solution {
public:
    int minDistance(string word1, string word2) {
        int firstLength = static_cast<int>(word1.size());
        int secondLength = static_cast<int>(word2.size());
        vector<int> previous(secondLength + 1);
        vector<int> current(secondLength + 1);

        for (int j = 0; j <= secondLength; j++) {
            previous[j] = j;
        }

        for (int i = 1; i <= firstLength; i++) {
            current[0] = i;

            for (int j = 1; j <= secondLength; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    current[j] = previous[j - 1];
                } else {
                    current[j] = 1 + min({
                        current[j - 1],
                        previous[j],
                        previous[j - 1]
                    });
                }
            }

            previous = current;
        }

        return previous[secondLength];
    }
};
