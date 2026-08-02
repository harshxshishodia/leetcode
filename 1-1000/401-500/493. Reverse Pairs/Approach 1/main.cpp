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
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> allValues;
        for (int num : nums) {
            allValues.push_back((long long)num);
            allValues.push_back(2LL * num);
        }
        sort(allValues.begin(), allValues.end());
        allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
        treeSize = allValues.size();
        segmentTree.assign(4 * treeSize, 0);
        int totalReversePairs = 0;
        for (int num : nums) {
            int doubleValueRank = lower_bound(allValues.begin(), allValues.end(), 2LL * num) - allValues.begin() + 1;
            totalReversePairs += queryTree(0, 1, treeSize, doubleValueRank + 1, treeSize);
            int currentValueRank = lower_bound(allValues.begin(), allValues.end(), (long long)num) - allValues.begin() + 1;
            updateTree(0, 1, treeSize, currentValueRank, 1);
        }
        return totalReversePairs;
    }
};
