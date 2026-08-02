class Solution {
    vector<int> segmentTree;
    int treeSize;

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int charBitmask) {
        if (left == right) {
            segmentTree[nodeIndex] = charBitmask;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, charBitmask);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, charBitmask);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] ^ segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) ^
               queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    vector<bool> palindromicPathQueries(int n, vector<vector<int>>& edges, string s, vector<vector<int>>& queries) {
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);

        for (int i = 0; i < n; i++) {
            updateTree(0, 0, n - 1, i, 1 << (s[i] - 'a'));
        }

        vector<bool> resultAnswers;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int node = q[1];
                char newChar = q[2] + 'a';
                updateTree(0, 0, n - 1, node, 1 << (newChar - 'a'));
            } else if (type == 2) {
                int u = q[1], v = q[2];
                int pathMask = queryTree(0, 0, n - 1, min(u, v), max(u, v));
                resultAnswers.push_back(__builtin_popcount(pathMask) <= 1);
            }
        }
        return resultAnswers;
    }
};
