class Solution {
    vector<int> segmentTree;
    vector<int> lazyTree;
    int treeSize;
    void pushLazy(int nodeIndex, int left, int right) {
        if (lazyTree[nodeIndex] != 0) {
            int mid = left + (right - left) / 2;
            segmentTree[2 * nodeIndex + 1] = (mid - left + 1);
            lazyTree[2 * nodeIndex + 1] = 1;
            segmentTree[2 * nodeIndex + 2] = (right - mid);
            lazyTree[2 * nodeIndex + 2] = 1;
            lazyTree[nodeIndex] = 0;
        }
    }
    void updateRange(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            segmentTree[nodeIndex] = (right - left + 1);
            lazyTree[nodeIndex] = 1;
            return;
        }
        pushLazy(nodeIndex, left, right);
        int mid = left + (right - left) / 2;
        updateRange(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        updateRange(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }
    int queryRange(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        pushLazy(nodeIndex, left, right);
        int mid = left + (right - left) / 2;
        return queryRange(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryRange(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int maxCoordinate = 0;
        for (const auto& interval : paint) {
            maxCoordinate = max(maxCoordinate, interval[1]);
        }
        treeSize = maxCoordinate + 1;
        segmentTree.assign(4 * treeSize, 0);
        lazyTree.assign(4 * treeSize, 0);
        vector<int> resultPainted;
        for (const auto& interval : paint) {
            int startPos = interval[0];
            int endPos = interval[1] - 1;
            int alreadyPaintedCount = queryRange(0, 0, treeSize - 1, startPos, endPos);
            int totalIntervalLength = endPos - startPos + 1;
            int newPaintedAmount = totalIntervalLength - alreadyPaintedCount;
            resultPainted.push_back(newPaintedAmount);
            updateRange(0, 0, treeSize - 1, startPos, endPos);
        }
        return resultPainted;
    }
};
