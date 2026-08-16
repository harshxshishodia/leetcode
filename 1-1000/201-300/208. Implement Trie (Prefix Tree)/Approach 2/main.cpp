class Trie {
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

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
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
        TrieNode* currentNode = root;
        for (char c : word) {
            int charIndex = c - 'a';
            if (currentNode->children[charIndex] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[charIndex];
        }
        return currentNode != nullptr && currentNode->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for (char c : prefix) {
            int charIndex = c - 'a';
            if (currentNode->children[charIndex] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[charIndex];
        }
        return currentNode != nullptr;
    }
};
