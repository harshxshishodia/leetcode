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
    long long minInversions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sortedUniqueNums = nums;
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        treeSize = sortedUniqueNums.size();

        segmentTree.assign(4 * treeSize, 0);

        long long currentInversions = 0;
        for (int i = 0; i < k; i++) {
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i]) - sortedUniqueNums.begin() + 1;
            currentInversions += queryTree(0, 1, treeSize, rankIndex + 1, treeSize);
            updateTree(0, 1, treeSize, rankIndex, 1);
        }

        long long minInversionCount = currentInversions;

        for (int i = k; i < n; i++) {
            int oldRankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i - k]) - sortedUniqueNums.begin() + 1;
            updateTree(0, 1, treeSize, oldRankIndex, -1);
            currentInversions -= queryTree(0, 1, treeSize, 1, oldRankIndex - 1);

            int newRankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i]) - sortedUniqueNums.begin() + 1;
            currentInversions += queryTree(0, 1, treeSize, newRankIndex + 1, treeSize);
            updateTree(0, 1, treeSize, newRankIndex, 1);

            minInversionCount = min(minInversionCount, currentInversions);
        }

        return minInversionCount;
    }
};
