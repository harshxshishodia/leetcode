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
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        int maxArea = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || points[i][0] >= points[j][0] || points[i][1] >= points[j][1]) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                bool hasCorner1 = false, hasCorner2 = false;
                for (int k = 0; k < n; k++) {
                    if (points[k][0] == x1 && points[k][1] == y2) hasCorner1 = true;
                    if (points[k][0] == x2 && points[k][1] == y1) hasCorner2 = true;
                }
                if (!hasCorner1 || !hasCorner2) continue;
                treeSize = 101;
                segmentTree.assign(4 * treeSize, 0);
                for (int k = 0; k < n; k++) {
                    if (points[k][0] >= x1 && points[k][0] <= x2) {
                        updateTree(0, 0, treeSize - 1, points[k][1], 1);
                    }
                }
                int countInsideAndBorder = queryTree(0, 0, treeSize - 1, y1, y2);
                if (countInsideAndBorder == 4) {
                    maxArea = max(maxArea, (x2 - x1) * (y2 - y1));
                }
            }
        }
        return maxArea;
    }
};
