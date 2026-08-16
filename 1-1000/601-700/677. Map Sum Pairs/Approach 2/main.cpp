class MapSum {
    struct TrieNode {
        TrieNode* children[26] = {};
        int prefixSum = 0;
    };

    TrieNode* root;
    unordered_map<string, int> keyValueMap;

public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        int delta = val;
        if (keyValueMap.count(key)) {
            delta -= keyValueMap[key];
        }
        keyValueMap[key] = val;

        TrieNode* currentNode = root;
        currentNode->prefixSum += delta;
        for (char c : key) {
            int index = c - 'a';
            if (!currentNode->children[index]) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
            currentNode->prefixSum += delta;
        }
    }

    int sum(string prefix) {
        TrieNode* currentNode = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!currentNode->children[index]) {
                return 0;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->prefixSum;
    }
};
