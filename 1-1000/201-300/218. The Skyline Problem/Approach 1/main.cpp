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
    void getHeights(int nodeIndex, int left, int right, vector<int>& intervalHeights) {
        if (left == right) {
            intervalHeights[left] = segmentTree[nodeIndex];
            return;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        getHeights(2 * nodeIndex + 1, left, mid, intervalHeights);
        getHeights(2 * nodeIndex + 2, mid + 1, right, intervalHeights);
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> xCoordinates;
        for (const auto& building : buildings) {
            xCoordinates.push_back(building[0]);
            xCoordinates.push_back(building[1]);
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        xCoordinates.erase(unique(xCoordinates.begin(), xCoordinates.end()), xCoordinates.end());
        int numCoordinates = xCoordinates.size();
        if (numCoordinates <= 1) return {};
        treeSize = numCoordinates - 1;
        segmentTree.assign(4 * treeSize, 0);
        lazyTree.assign(4 * treeSize, 0);
        for (const auto& building : buildings) {
            int leftRank = lower_bound(xCoordinates.begin(), xCoordinates.end(), building[0]) - xCoordinates.begin();
            int rightRank = lower_bound(xCoordinates.begin(), xCoordinates.end(), building[1]) - xCoordinates.begin() - 1;
            updateRange(0, 0, treeSize - 1, leftRank, rightRank, building[2]);
        }
        vector<int> intervalHeights(treeSize, 0);
        getHeights(0, 0, treeSize - 1, intervalHeights);
        vector<vector<int>> skylineKeyPoints;
        int currentHeight = 0;
        for (int i = 0; i < treeSize; i++) {
            if (intervalHeights[i] != currentHeight) {
                currentHeight = intervalHeights[i];
                skylineKeyPoints.push_back({xCoordinates[i], currentHeight});
            }
        }
        if (currentHeight != 0) {
            skylineKeyPoints.push_back({xCoordinates[treeSize], 0});
        }
        return skylineKeyPoints;
    }
};
