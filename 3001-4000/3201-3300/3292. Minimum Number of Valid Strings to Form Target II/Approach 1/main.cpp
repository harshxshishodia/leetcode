class Solution {
    struct TrieNode {
        int children[26];
        int failLink;
        int maxDepth;
        TrieNode() : failLink(0), maxDepth(0) {
            fill(begin(children), end(children), 0);
        }
    };

    vector<TrieNode> trie;

    void insertWord(const string& word) {
        int currentNode = 0;
        int depth = 0;
        for (char c : word) {
            int charIdx = c - 'a';
            if (!trie[currentNode].children[charIdx]) {
                trie[currentNode].children[charIdx] = trie.size();
                trie.emplace_back();
            }
            currentNode = trie[currentNode].children[charIdx];
            depth++;
            trie[currentNode].maxDepth = max(trie[currentNode].maxDepth, depth);
        }
    }

    void buildACAutomaton() {
        queue<int> nodeQueue;
        for (int c = 0; c < 26; c++) {
            if (trie[0].children[c]) {
                nodeQueue.push(trie[0].children[c]);
            }
        }
        while (!nodeQueue.empty()) {
            int curr = nodeQueue.front();
            nodeQueue.pop();
            for (int c = 0; c < 26; c++) {
                if (trie[curr].children[c]) {
                    trie[trie[curr].children[c]].failLink = trie[trie[curr].failLink].children[c];
                    nodeQueue.push(trie[curr].children[c]);
                } else {
                    trie[curr].children[c] = trie[trie[curr].failLink].children[c];
                }
            }
        }
    }

    vector<long long> segmentTree;
    int treeSize;

    void updateTree(int nodeIndex, int left, int right, int updateIndex, long long value) {
        if (left == right) {
            segmentTree[nodeIndex] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = min(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    long long queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return INT_MAX;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return min(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    int minValidStrings(vector<string>& words, string target) {
        trie.emplace_back();
        for (const string& word : words) {
            insertWord(word);
        }
        buildACAutomaton();

        int n = target.length();
        vector<int> maxMatchLength(n, 0);
        int currentNode = 0;
        int currentMatch = 0;

        for (int i = 0; i < n; i++) {
            int charIdx = target[i] - 'a';
            currentNode = trie[currentNode].children[charIdx];
            if (currentNode != 0) {
                currentMatch++;
            } else {
                currentMatch = 0;
            }
            maxMatchLength[i] = currentMatch;
        }

        treeSize = n + 1;
        segmentTree.assign(4 * treeSize, INT_MAX);
        updateTree(0, 0, n, n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int matchLen = maxMatchLength[i];
            if (matchLen > 0) {
                long long bestNext = queryTree(0, 0, n, i + 1, i + matchLen);
                if (bestNext != INT_MAX) {
                    updateTree(0, 0, n, i, bestNext + 1);
                }
            }
        }

        long long result = queryTree(0, 0, n, 0, 0);
        return result == INT_MAX ? -1 : result;
    }
};
