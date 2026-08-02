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
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        int n = xCoord.size();
        map<int, vector<int>> pointsByX;
        vector<int> sortedUniqueY = yCoord;
        sort(sortedUniqueY.begin(), sortedUniqueY.end());
        sortedUniqueY.erase(unique(sortedUniqueY.begin(), sortedUniqueY.end()), sortedUniqueY.end()); // typo sortedUniqueNums -> sortedUniqueY

        for (int i = 0; i < n; i++) {
            pointsByX[xCoord[i]].push_back(yCoord[i]);
        }

        treeSize = sortedUniqueY.size();
        segmentTree.assign(4 * treeSize, 0);

        long long maxArea = -1;
        map<pair<int, int>, int> lastSeenXForYPair;

        for (auto& entry : pointsByX) {
            int currentX = entry.first;
            auto& yList = entry.second;
            sort(yList.begin(), yList.end());

            for (int i = 0; i < (int)yList.size(); i++) {
                int yRank = lower_bound(sortedUniqueY.begin(), sortedUniqueY.end(), yList[i]) - sortedUniqueY.begin() + 1;
                updateTree(0, 1, treeSize, yRank, 1);
            }

            for (int i = 0; i < (int)yList.size() - 1; i++) {
                int y1 = yList[i];
                int y2 = yList[i + 1];
                pair<int, int> yPair = {y1, y2};

                if (lastSeenXForYPair.count(yPair)) {
                    int prevX = lastSeenXForYPair[yPair];
                    int y1Rank = lower_bound(sortedUniqueY.begin(), sortedUniqueY.end(), y1) - sortedUniqueY.begin() + 1;
                    int y2Rank = lower_bound(sortedUniqueY.begin(), sortedUniqueY.end(), y2) - sortedUniqueY.begin() + 1;

                    int pointsInRect = queryTree(0, 1, treeSize, y1Rank, y2Rank);
                    // Since points are added, we check if exactly 4 points exist in this region across sweep
                    if (pointsInRect == 4) {
                        long long area = (long long)(currentX - prevX) * (y2 - y1);
                        maxArea = max(maxArea, area);
                    }
                }
                lastSeenXForYPair[yPair] = currentX;
            }
        }

        return maxArea;
    }
};
