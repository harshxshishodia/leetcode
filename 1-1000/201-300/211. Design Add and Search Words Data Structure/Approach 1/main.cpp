class WordDictionary {
    unordered_map<int, vector<string>> wordsByLength;

public:
    WordDictionary() {}

    void addWord(string word) {
        wordsByLength[word.size()].push_back(word);
    }

    bool search(string word) {
        int len = static_cast<int>(word.size());
        auto it = wordsByLength.find(len);
        if (it == wordsByLength.end()) return false;

        for (const string& storedWord : it->second) {
            bool matches = true;
            for (int i = 0; i < len; i++) {
                if (word[i] != '.' && word[i] != storedWord[i]) {
                    matches = false;
                    break;
                }
            }
            if (matches) return true;
        }
        return false;
    }
};
