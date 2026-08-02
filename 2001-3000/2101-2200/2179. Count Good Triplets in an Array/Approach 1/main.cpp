class Solution {
    vector<int> leftSegmentTree;
    vector<int> rightSegmentTree;
    int treeSize;
    void updateTree(vector<int>& segmentTree, int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] += value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(segmentTree, 2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }
    int queryTree(vector<int>& segmentTree, int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(segmentTree, 2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> posInNums2(n);
        for (int i = 0; i < n; i++) {
            posInNums2[nums2[i]] = i;
        }
        vector<int> transformedNums1(n);
        for (int i = 0; i < n; i++) {
            transformedNums1[i] = posInNums2[nums1[i]];
        }
        treeSize = n;
        leftSegmentTree.assign(4 * treeSize, 0);
        rightSegmentTree.assign(4 * treeSize, 0);
        for (int i = 0; i < n; i++) {
            updateTree(rightSegmentTree, 0, 0, treeSize - 1, transformedNums1[i], 1);
        }
        long long totalGoodTriplets = 0;
        for (int i = 0; i < n; i++) {
            int pos = transformedNums1[i];
            updateTree(rightSegmentTree, 0, 0, treeSize - 1, pos, -1);
            long long leftSmaller = queryTree(leftSegmentTree, 0, 0, treeSize - 1, 0, pos - 1);
            long long rightGreater = queryTree(rightSegmentTree, 0, 0, treeSize - 1, pos + 1, treeSize - 1);
            totalGoodTriplets += leftSmaller * rightGreater;
            updateTree(leftSegmentTree, 0, 0, treeSize - 1, pos, 1);
        }
        return totalGoodTriplets;
    }
};
