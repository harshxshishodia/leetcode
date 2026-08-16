class StreamChecker {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isWordEnd = false;
    };

    TrieNode* root;
    deque<char> charStreamHistory;
    int maxWordLength;

    void insertReversed(const string& word) {
        TrieNode* curr = root;
        for (int i = static_cast<int>(word.size()) - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWordEnd = true;
    }

public:
    StreamChecker(vector<string>& words) : maxWordLength(0) {
        root = new TrieNode();
        for (const string& w : words) {
            insertReversed(w);
            maxWordLength = max(maxWordLength, static_cast<int>(w.size()));
        }
    }

    bool query(char letter) {
        charStreamHistory.push_front(letter);
        if (static_cast<int>(charStreamHistory.size()) > maxWordLength) {
            charStreamHistory.pop_back();
        }

        TrieNode* curr = root;
        for (char c : charStreamHistory) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
            if (curr->isWordEnd) {
                return true;
            }
        }
        return false;
    }
};
