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
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallerCounts(n, 0);
        vector<int> sortedUniqueNums = nums;
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        treeSize = sortedUniqueNums.size();
        segmentTree.assign(4 * treeSize, 0);
        for (int i = n - 1; i >= 0; i--) {
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i]) - sortedUniqueNums.begin() + 1;
            smallerCounts[i] = queryTree(0, 1, treeSize, 1, rankIndex - 1);
            updateTree(0, 1, treeSize, rankIndex, 1);
        }
        return smallerCounts;
    }
};
