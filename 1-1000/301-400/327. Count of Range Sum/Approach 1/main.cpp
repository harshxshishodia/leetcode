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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        vector<long long> allValues;
        for (long long sumVal : prefixSums) {
            allValues.push_back(sumVal);
            allValues.push_back(sumVal - upper);
            allValues.push_back(sumVal - lower);
        }
        sort(allValues.begin(), allValues.end());
        allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
        treeSize = allValues.size();
        segmentTree.assign(4 * treeSize, 0);
        int validRangeSumCount = 0;
        for (long long sumVal : prefixSums) {
            int leftBoundRank = lower_bound(allValues.begin(), allValues.end(), sumVal - upper) - allValues.begin() + 1;
            int rightBoundRank = lower_bound(allValues.begin(), allValues.end(), sumVal - lower) - allValues.begin() + 1;
            validRangeSumCount += queryTree(0, 1, treeSize, leftBoundRank, rightBoundRank);
            int currentSumRank = lower_bound(allValues.begin(), allValues.end(), sumVal) - allValues.begin() + 1;
            updateTree(0, 1, treeSize, currentSumRank, 1);
        }
        return validRangeSumCount;
    }
};
