class Solution {
    vector<int> segmentTree;
    int treeSize;
    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] = max(segmentTree[nodeIndex], value);
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
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
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
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }
        treeSize = maxVal;
        segmentTree.assign(4 * treeSize + 4, 0);
        int maxLisLength = 0;
        for (int num : nums) {
            int queryLeft = max(1, num - k);
            int queryRight = num - 1;
            int bestPrev = queryTree(0, 1, treeSize, queryLeft, queryRight);
            int currentDp = bestPrev + 1;
            maxLisLength = max(maxLisLength, currentDp);
            updateTree(0, 1, treeSize, num, currentDp);
        }
        return maxLisLength;
    }
};
