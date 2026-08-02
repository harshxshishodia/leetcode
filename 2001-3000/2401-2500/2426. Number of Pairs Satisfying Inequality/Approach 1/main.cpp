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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<long long> diffArr(n);
        vector<long long> allValues;
        for (int i = 0; i < n; i++) {
            diffArr[i] = nums1[i] - nums2[i];
            allValues.push_back(diffArr[i]);
            allValues.push_back(diffArr[i] + diff);
        }
        sort(allValues.begin(), allValues.end());
        allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
        treeSize = allValues.size();
        segmentTree.assign(4 * treeSize, 0);
        long long validPairsCount = 0;
        for (int i = 0; i < n; i++) {
            int targetRank = upper_bound(allValues.begin(), allValues.end(), diffArr[i] + diff) - allValues.begin();
            validPairsCount += queryTree(0, 1, treeSize, 1, targetRank);
            int currentRank = lower_bound(allValues.begin(), allValues.end(), diffArr[i]) - allValues.begin() + 1;
            updateTree(0, 1, treeSize, currentRank, 1);
        }
        return validPairsCount;
    }
};
