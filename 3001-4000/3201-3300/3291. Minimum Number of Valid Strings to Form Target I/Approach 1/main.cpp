class Solution {
    struct TrieNode {
        TrieNode* children[26];
        TrieNode() {
            fill(begin(children), end(children), nullptr);
        }
    };
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
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
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
        TrieNode* rootNode = new TrieNode();
        for (const string& word : words) {
            TrieNode* currentNode = rootNode;
            for (char c : word) {
                if (!currentNode->children[c - 'a']) {
                    currentNode->children[c - 'a'] = new TrieNode();
                }
                currentNode = currentNode->children[c - 'a'];
            }
        }
        int n = target.length();
        treeSize = n + 1;
        segmentTree.assign(4 * treeSize, INT_MAX);
        updateTree(0, 0, n, n, 0);
        for (int i = n - 1; i >= 0; i--) {
            TrieNode* currentNode = rootNode;
            int maxMatchLength = 0;
            for (int j = i; j < n; j++) {
                if (!currentNode->children[target[j] - 'a']) {
                    break;
                }
                currentNode = currentNode->children[target[j] - 'a'];
                maxMatchLength++;
            }
            if (maxMatchLength > 0) {
                long long bestNext = queryTree(0, 0, n, i + 1, i + maxMatchLength);
                if (bestNext != INT_MAX) {
                    updateTree(0, 0, n, i, bestNext + 1);
                }
            }
        }
        long long result = queryTree(0, 0, n, 0, 0);
        return result == INT_MAX ? -1 : result;
    }
};
