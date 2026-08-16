class Trie {
    struct TrieNode {
        TrieNode* children[26] = {};
        int wordsEndingHere = 0;
        int wordsStartingWithPrefix = 0;
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int charIndex = c - 'a';
            if (!currentNode->children[charIndex]) {
                currentNode->children[charIndex] = new TrieNode();
            }
            currentNode = currentNode->children[charIndex];
            currentNode->wordsStartingWithPrefix++;
        }
        currentNode->wordsEndingHere++;
    }

    int countWordsEqualTo(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int charIndex = c - 'a';
            if (!currentNode->children[charIndex]) {
                return 0;
            }
            currentNode = currentNode->children[charIndex];
        }
        return currentNode->wordsEndingHere;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* currentNode = root;
        for (char c : prefix) {
            int charIndex = c - 'a';
            if (!currentNode->children[charIndex]) {
                return 0;
            }
            currentNode = currentNode->children[charIndex];
        }
        return currentNode->wordsStartingWithPrefix;
    }

    void erase(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int charIndex = c - 'a';
            currentNode = currentNode->children[charIndex];
            currentNode->wordsStartingWithPrefix--;
        }
        currentNode->wordsEndingHere--;
    }
};
