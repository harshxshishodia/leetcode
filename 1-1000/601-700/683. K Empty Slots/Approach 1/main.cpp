class Solution {
    vector<int> segmentTree;
    int treeSize;
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
    int kEmptySlots(vector<int>& bulbs, int k) {
        treeSize = bulbs.size();
        segmentTree.assign(4 * treeSize + 4, 0);
        for (int day = 1; day <= treeSize; day++) {
            int pos = bulbs[day - 1];
            updateTree(0, 1, treeSize, pos, 1);
            if (pos - k - 1 >= 1) {
                int leftNeighborOn = queryTree(0, 1, treeSize, pos - k - 1, pos - k - 1);
                int middleOffSum = queryTree(0, 1, treeSize, pos - k, pos - 1);
                if (leftNeighborOn == 1 && middleOffSum == 0) {
                    return day;
                }
            }
            if (pos + k + 1 <= treeSize) {
                int rightNeighborOn = queryTree(0, 1, treeSize, pos + k + 1, pos + k + 1);
                int middleOffSum = queryTree(0, 1, treeSize, pos + 1, pos + k);
                if (rightNeighborOn == 1 && middleOffSum == 0) {
                    return day;
                }
            }
        }
        return -1;
    }
};
