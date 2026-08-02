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
    long long countSubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        treeSize = 2 * n + 1;
        segmentTree.assign(4 * treeSize, 0);

        int currentPrefixSum = 0;
        int offset = n;
        long long validSubarraysCount = 0;

        updateTree(0, 0, treeSize - 1, currentPrefixSum + offset, 1);

        for (int num : nums) {
            currentPrefixSum += (num == target) ? 1 : -1;
            int strictlyLessCount = queryTree(0, 0, treeSize - 1, 0, currentPrefixSum + offset - 1);
            validSubarraysCount += strictlyLessCount;
            updateTree(0, 0, treeSize - 1, currentPrefixSum + offset, 1);
        }

        return validSubarraysCount;
    }
};
