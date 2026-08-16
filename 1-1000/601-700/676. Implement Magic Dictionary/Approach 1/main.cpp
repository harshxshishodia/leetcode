class MagicDictionary {
    unordered_map<int, vector<string>> wordsByLength;

public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        wordsByLength.clear();
        for (const string& word : dictionary) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    bool search(string searchWord) {
        int targetLength = static_cast<int>(searchWord.size());
        auto it = wordsByLength.find(targetLength);
        if (it == wordsByLength.end()) return false;

        for (const string& candidate : it->second) {
            int differenceCount = 0;
            for (int i = 0; i < targetLength; i++) {
                if (candidate[i] != searchWord[i]) {
                    differenceCount++;
                    if (differenceCount > 1) break;
                }
            }
            if (differenceCount == 1) {
                return true;
            }
        }
        return false;
    }
};
