class WordDictionary {
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    TrieNode* root;

    bool matchHelper(const string& word, int index, TrieNode* node) {
        if (node == nullptr) return false;
        if (index == static_cast<int>(word.size())) return node->isEndOfWord;

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && matchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int charIndex = ch - 'a';
            return matchHelper(word, index + 1, node->children[charIndex]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int charIndex = c - 'a';
            if (currentNode->children[charIndex] == nullptr) {
                currentNode->children[charIndex] = new TrieNode();
            }
            currentNode = currentNode->children[charIndex];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(string word) {
        return matchHelper(word, 0, root);
    }
};
