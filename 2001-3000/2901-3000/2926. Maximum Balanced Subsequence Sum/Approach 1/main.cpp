class Solution {
    vector<long long> segmentTree;
    int treeSize;
    void updateTree(int nodeIndex, int left, int right, int updateIndex, long long value) {
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
    long long queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
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
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> transformedVals(n);
        for (int i = 0; i < n; i++) {
            transformedVals[i] = (long long)nums[i] - i;
        }
        vector<long long> sortedUniqueVals = transformedVals;
        sort(sortedUniqueVals.begin(), sortedUniqueVals.end());
        sortedUniqueVals.erase(unique(sortedUniqueVals.begin(), sortedUniqueVals.end()), sortedUniqueVals.end());
        treeSize = sortedUniqueVals.size();
        segmentTree.assign(4 * treeSize, 0);

        long long overallMaxSum = LLONG_MIN;
        for (int num : nums) {
            overallMaxSum = max(overallMaxSum, (long long)num);
        }
        if (overallMaxSum <= 0) return overallMaxSum;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) continue;
            int rankIndex = lower_bound(sortedUniqueVals.begin(), sortedUniqueVals.end(), transformedVals[i]) - sortedUniqueVals.begin() + 1;
            long long bestPrev = queryTree(0, 1, treeSize, 1, rankIndex);
            long long currentDp = nums[i] + bestPrev;
            overallMaxSum = max(overallMaxSum, currentDp);
            updateTree(0, 1, treeSize, rankIndex, currentDp);
        }

        return overallMaxSum;
    }
};
