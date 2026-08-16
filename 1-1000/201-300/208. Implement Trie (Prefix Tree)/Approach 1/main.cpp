class Trie {
    unordered_set<string> wordSet;
    unordered_set<string> prefixSet;

public:
    Trie() {}

    void insert(string word) {
        wordSet.insert(word);
        string currentPrefix = "";
        for (char c : word) {
            currentPrefix += c;
            prefixSet.insert(currentPrefix);
        }
    }

    bool search(string word) {
        return wordSet.find(word) != wordSet.end();
    }

    bool startsWith(string prefix) {
        return prefixSet.find(prefix) != prefixSet.end();
    }
};
