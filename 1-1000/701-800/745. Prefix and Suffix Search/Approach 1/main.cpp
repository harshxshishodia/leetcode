class WordFilter {
    struct TrieNode {
        TrieNode* children[27] = {};
        int maxWeight = -1;
    };

    TrieNode* root;

    void insertWord(const string& word, int weight) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = (c == '{') ? 26 : (c - 'a');
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->maxWeight = weight;
        }
    }

public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for (int weight = 0; weight < static_cast<int>(words.size()); weight++) {
            const string& w = words[weight];
            int len = static_cast<int>(w.size());
            for (int i = 0; i <= len; i++) {
                string combined = w.substr(i) + "{" + w;
                insertWord(combined, weight);
            }
        }
    }

    int f(string pref, string suff) {
        string query = suff + "{" + pref;
        TrieNode* curr = root;
        for (char c : query) {
            int idx = (c == '{') ? 26 : (c - 'a');
            if (!curr->children[idx]) {
                return -1;
            }
            curr = curr->children[idx];
        }
        return curr->maxWeight;
    }
};
