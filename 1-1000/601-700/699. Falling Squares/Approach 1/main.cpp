class Solution {
    vector<int> segmentTree;
    vector<int> lazyTree;
    int treeSize;
    void pushLazy(int nodeIndex) {
        if (lazyTree[nodeIndex] > 0) {
            int lazyVal = lazyTree[nodeIndex];
            segmentTree[2 * nodeIndex + 1] = max(segmentTree[2 * nodeIndex + 1], lazyVal);
            lazyTree[2 * nodeIndex + 1] = max(lazyTree[2 * nodeIndex + 1], lazyVal);
            segmentTree[2 * nodeIndex + 2] = max(segmentTree[2 * nodeIndex + 2], lazyVal);
            lazyTree[2 * nodeIndex + 2] = max(lazyTree[2 * nodeIndex + 2], lazyVal);
            lazyTree[nodeIndex] = 0;
        }
    }
    void updateRange(int nodeIndex, int left, int right, int queryLeft, int queryRight, int heightValue) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            segmentTree[nodeIndex] = max(segmentTree[nodeIndex], heightValue);
            lazyTree[nodeIndex] = max(lazyTree[nodeIndex], heightValue);
            return;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        updateRange(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, heightValue);
        updateRange(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, heightValue);
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }
    int queryRange(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        return max(queryRange(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryRange(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> xCoordinates;
        for (const auto& pos : positions) {
            xCoordinates.push_back(pos[0]);
            xCoordinates.push_back(pos[0] + pos[1]);
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        xCoordinates.erase(unique(xCoordinates.begin(), xCoordinates.end()), xCoordinates.end());
        int numCoordinates = xCoordinates.size();
        treeSize = numCoordinates - 1;
        segmentTree.assign(4 * treeSize, 0);
        lazyTree.assign(4 * treeSize, 0);
        vector<int> resultHeights;
        int overallMaxHeight = 0;
        for (const auto& pos : positions) {
            int leftRank = lower_bound(xCoordinates.begin(), xCoordinates.end(), pos[0]) - xCoordinates.begin();
            int rightRank = lower_bound(xCoordinates.begin(), xCoordinates.end(), pos[0] + pos[1]) - xCoordinates.begin() - 1;
            int baseHeight = queryRange(0, 0, treeSize - 1, leftRank, rightRank);
            int newHeight = baseHeight + pos[1];
            updateRange(0, 0, treeSize - 1, leftRank, rightRank, newHeight);
            overallMaxHeight = max(overallMaxHeight, newHeight);
            resultHeights.push_back(overallMaxHeight);
        }
        return resultHeights;
    }
};
