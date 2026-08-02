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
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return max(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxCoord = 0;
        for (const auto& q : queries) {
            maxCoord = max(maxCoord, q[1]);
        }
        maxCoord = min(maxCoord + 1, 50005);
        treeSize = maxCoord + 1;
        segmentTree.assign(4 * treeSize, 0);

        set<int> obstacleSet;
        obstacleSet.insert(0);
        obstacleSet.insert(treeSize);
        updateTree(0, 0, treeSize - 1, treeSize, treeSize);

        vector<bool> resultAnswers;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = obstacleSet.lower_bound(x);
                int nextObstacle = *it;
                int prevObstacle = *prev(it);

                obstacleSet.insert(x);
                updateTree(0, 0, treeSize - 1, x, x - prevObstacle);
                updateTree(0, 0, treeSize - 1, nextObstacle, nextObstacle - x);
            } else if (type == 2) {
                int x = q[1];
                int sz = q[2];
                auto it = obstacleSet.upper_bound(x);
                int prevObstacle = *prev(it);

                int maxGapInPrev = queryTree(0, 0, treeSize - 1, 0, prevObstacle);
                int gapAtEnd = x - prevObstacle;

                if (maxGapInPrev >= sz || gapAtEnd >= sz) {
                    resultAnswers.push_back(true);
                } else {
                    resultAnswers.push_back(false);
                }
            }
        }

        return resultAnswers;
    }
};
