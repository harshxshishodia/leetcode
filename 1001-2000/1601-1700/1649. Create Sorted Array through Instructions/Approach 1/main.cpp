class Solution {
    vector<int> segmentTree;
    int treeSize;
    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] += value;
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
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
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
    int createSortedArray(vector<int>& instructions) {
        int maxVal = 0;
        for (int x : instructions) {
            maxVal = max(maxVal, x);
        }
        treeSize = maxVal;
        segmentTree.assign(4 * treeSize + 4, 0);
        long long totalCost = 0;
        long long modVal = 1000000007;
        for (int x : instructions) {
            int strictlyLess = queryTree(0, 1, treeSize, 1, x - 1);
            int strictlyGreater = queryTree(0, 1, treeSize, x + 1, treeSize);
            totalCost = (totalCost + min(strictlyLess, strictlyGreater)) % modVal;
            updateTree(0, 1, treeSize, x, 1);
        }
        return totalCost;
    }
};
