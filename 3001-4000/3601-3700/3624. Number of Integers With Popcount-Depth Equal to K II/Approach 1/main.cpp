class Solution {
    vector<int> segmentTree;
    int treeSize;

    int getPopcountDepth(long long n) {
        if (n <= 1) return 0;
        int depth = 0;
        while (n > 1) {
            n = __builtin_popcountll(n);
            depth++;
        }
        return depth;
    }

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
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
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    int countIntegersWithDepth(long long low, long long high, int targetK) {
        treeSize = 100001;
        segmentTree.assign(4 * treeSize, 0);

        for (int i = 1; i < treeSize; i++) {
            if (getPopcountDepth(i) == targetK) {
                updateTree(0, 1, treeSize - 1, i, 1);
            }
        }

        int queryLow = max(1LL, low);
        int queryHigh = min((long long)treeSize - 1, high);

        return queryTree(0, 1, treeSize - 1, queryLow, queryHigh);
    }
};
