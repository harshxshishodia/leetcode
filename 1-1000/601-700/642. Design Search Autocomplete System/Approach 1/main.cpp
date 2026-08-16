class AutocompleteSystem {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        unordered_map<string, int> sentenceCounts;
    };

    TrieNode* root;
    TrieNode* currentSearchNode;
    string currentInputBuffer;

    void insertSentence(const string& sentence, int times) {
        TrieNode* curr = root;
        for (char c : sentence) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->sentenceCounts[sentence] += times;
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        currentSearchNode = root;
        currentInputBuffer = "";
        for (int i = 0; i < static_cast<int>(sentences.size()); i++) {
            insertSentence(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insertSentence(currentInputBuffer, 1);
            currentInputBuffer = "";
            currentSearchNode = root;
            return {};
        }

        currentInputBuffer += c;
        if (!currentSearchNode || !currentSearchNode->children.count(c)) {
            currentSearchNode = nullptr;
            return {};
        }

        currentSearchNode = currentSearchNode->children[c];
        auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        };

        vector<pair<string, int>> candidates(currentSearchNode->sentenceCounts.begin(), currentSearchNode->sentenceCounts.end());
        sort(candidates.begin(), candidates.end(), comp);

        vector<string> topResults;
        for (int i = 0; i < min(3, static_cast<int>(candidates.size())); i++) {
            topResults.push_back(candidates[i].first);
        }
        return topResults;
    }
};
