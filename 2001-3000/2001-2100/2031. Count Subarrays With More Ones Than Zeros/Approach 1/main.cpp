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
        segmentTree[nodeIndex] = (segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2]) % 1000000007;
    }
    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return (queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
                queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight)) % 1000000007;
    }
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int numElements = nums.size();
        treeSize = 2 * numElements + 1;
        segmentTree.assign(4 * treeSize, 0);
        int currentPrefixSum = 0;
        int offset = numElements;
        long long validSubarraysCount = 0;
        long long moduloValue = 1000000007;
        updateTree(0, 0, treeSize - 1, currentPrefixSum + offset, 1);
        for (int num : nums) {
            currentPrefixSum += (num == 1) ? 1 : -1;
            int strictlyLessCount = queryTree(0, 0, treeSize - 1, 0, currentPrefixSum + offset - 1);
            validSubarraysCount = (validSubarraysCount + strictlyLessCount) % moduloValue;
            updateTree(0, 0, treeSize - 1, currentPrefixSum + offset, 1);
        }
        return validSubarraysCount;
    }
    int subarraysWithMoreOnesThanZeros(vector<int>& nums) {
        return subarraysWithMoreZerosThanOnes(nums);
    }
    int countSubarrays(vector<int>& nums) {
        return subarraysWithMoreZerosThanOnes(nums);
    }
};
