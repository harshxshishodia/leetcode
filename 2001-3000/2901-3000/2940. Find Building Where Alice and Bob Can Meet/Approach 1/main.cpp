class Solution {
    vector<int> segmentTree;
    int treeSize;

    void buildTree(int nodeIndex, int left, int right, const vector<int>& heights) {
        if (left == right) {
            segmentTree[nodeIndex] = heights[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, heights);
        buildTree(2 * nodeIndex + 2, mid + 1, right, heights);
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    int queryFirstGreater(int nodeIndex, int left, int right, int queryLeft, int targetHeight) {
        if (right < queryLeft || segmentTree[nodeIndex] <= targetHeight) {
            return -1;
        }
        if (left == right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        int leftRes = queryFirstGreater(2 * nodeIndex + 1, left, mid, queryLeft, targetHeight);
        if (leftRes != -1) return leftRes;
        return queryFirstGreater(2 * nodeIndex + 2, mid + 1, right, queryLeft, targetHeight);
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, heights);

        int numQueries = queries.size();
        vector<int> resultAnswers(numQueries, -1);

        for (int q = 0; q < numQueries; q++) {
            int i = min(queries[q][0], queries[q][1]);
            int j = max(queries[q][0], queries[q][1]);
            if (i == j || heights[i] < heights[j]) {
                resultAnswers[q] = j;
            } else {
                int targetHeight = max(heights[i], heights[j]);
                resultAnswers[q] = queryFirstGreater(0, 0, n - 1, j + 1, targetHeight);
            }
        }

        return resultAnswers;
    }
};
