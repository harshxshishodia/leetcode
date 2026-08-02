class Solution {
    vector<int> segmentTree;
    int treeSize;

    void buildTree(int nodeIndex, int left, int right) {
        if (left == right) {
            segmentTree[nodeIndex] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid);
        buildTree(2 * nodeIndex + 2, mid + 1, right);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1);

        vector<pair<int, int>> sortedElements(n);
        for (int i = 0; i < n; i++) {
            sortedElements[i] = {nums[i], i};
        }
        sort(sortedElements.begin(), sortedElements.end());

        long long totalOperations = 0;
        int currentPosition = 0;

        for (int i = 0; i < n; i++) {
            int targetPosition = sortedElements[i].second;
            if (targetPosition >= currentPosition) {
                totalOperations += queryTree(0, 0, n - 1, currentPosition, targetPosition);
            } else {
                totalOperations += queryTree(0, 0, n - 1, currentPosition, n - 1) + queryTree(0, 0, n - 1, 0, targetPosition);
            }
            updateTree(0, 0, n - 1, targetPosition, 0);
            currentPosition = targetPosition;
        }

        return totalOperations;
    }
};
