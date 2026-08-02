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
        segmentTree[nodeIndex] = min(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }
    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return INT_MAX / 2;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return min(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<long long> weightPrefix(n + 1, 0);
        vector<int> portChanges(n + 1, 0);
        for (int i = 0; i < n; i++) {
            weightPrefix[i + 1] = weightPrefix[i] + boxes[i][1];
            portChanges[i + 1] = portChanges[i] + (i > 0 && boxes[i][0] != boxes[i - 1][0] ? 1 : 0);
        }
        treeSize = n + 1;
        segmentTree.assign(4 * treeSize, INT_MAX / 2);
        vector<int> dp(n + 1, 0);
        updateTree(0, 0, n, 0, dp[0] - portChanges[1]);
        int validLeft = 0;
        for (int i = 1; i <= n; i++) {
            while (i - validLeft > maxBoxes || weightPrefix[i] - weightPrefix[validLeft] > maxWeight) {
                validLeft++;
            }
            int minPrevCost = queryTree(0, 0, n, validLeft, i - 1);
            dp[i] = minPrevCost + portChanges[i] + 2;
            if (i < n) {
                updateTree(0, 0, n, i, dp[i] - portChanges[i + 1]);
            }
        }
        return dp[n];
    }
};
