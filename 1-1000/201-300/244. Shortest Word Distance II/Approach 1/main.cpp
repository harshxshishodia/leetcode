class WordDistance {
    vector<string> words;

public:
    WordDistance(vector<string>& wordsDict) : words(wordsDict) {}

    int shortest(string word1, string word2) {
        int index1 = -1, index2 = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < static_cast<int>(words.size()); i++) {
            if (words[i] == word1) {
                index1 = i;
                if (index2 != -1) {
                    minDistance = min(minDistance, index1 - index2);
                }
            } else if (words[i] == word2) {
                index2 = i;
                if (index1 != -1) {
                    minDistance = min(minDistance, index2 - index1);
                }
            }
        }
        return minDistance;
    }
};
