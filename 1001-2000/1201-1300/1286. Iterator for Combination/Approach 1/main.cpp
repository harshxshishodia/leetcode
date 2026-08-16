class CombinationIterator {
    vector<string> combinations;
    int currentIndex;

    void generateCombinations(const string& chars, int length, int startIndex, string& current) {
        if (static_cast<int>(current.size()) == length) {
            combinations.push_back(current);
            return;
        }
        for (int i = startIndex; i < static_cast<int>(chars.size()); i++) {
            current.push_back(chars[i]);
            generateCombinations(chars, length, i + 1, current);
            current.pop_back();
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) : currentIndex(0) {
        string currentCombination = "";
        generateCombinations(characters, combinationLength, 0, currentCombination);
    }

    string next() {
        return combinations[currentIndex++];
    }

    bool hasNext() {
        return currentIndex < static_cast<int>(combinations.size());
    }
};
