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
    vector<int> shortestPathQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);

        vector<int> distFromRoot(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            distFromRoot[v] = distFromRoot[u] + w;
            updateTree(0, 0, n - 1, v, w);
        }

        vector<int> resultAnswers;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int u = q[1], v = q[2], w = q[3];
                updateTree(0, 0, n - 1, v, w);
            } else if (type == 2) {
                int u = q[1], v = q[2];
                int pathDist = abs(queryTree(0, 0, n - 1, u, u) - queryTree(0, 0, n - 1, v, v));
                resultAnswers.push_back(pathDist);
            }
        }
        return resultAnswers;
    }
};
