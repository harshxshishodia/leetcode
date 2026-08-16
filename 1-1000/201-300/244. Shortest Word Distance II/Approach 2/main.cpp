class WordDistance {
    unordered_map<string, vector<int>> wordIndices;

public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < static_cast<int>(wordsDict.size()); i++) {
            wordIndices[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        const auto& indices1 = wordIndices[word1];
        const auto& indices2 = wordIndices[word2];

        int i = 0, j = 0;
        int minDistance = INT_MAX;

        while (i < static_cast<int>(indices1.size()) && j < static_cast<int>(indices2.size())) {
            minDistance = min(minDistance, abs(indices1[i] - indices2[j]));
            if (indices1[i] < indices2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return minDistance;
    }
};
