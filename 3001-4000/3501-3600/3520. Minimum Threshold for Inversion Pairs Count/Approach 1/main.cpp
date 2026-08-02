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
    long long countInversions(const vector<int>& nums, const vector<int>& sortedUniqueNums, int threshold) {
        treeSize = sortedUniqueNums.size();
        segmentTree.assign(4 * treeSize, 0);
        long long totalInversions = 0;
        for (int num : nums) {
            int lowerBoundVal = num + 1;
            int upperBoundVal = num + threshold;
            int queryLeft = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), lowerBoundVal) - sortedUniqueNums.begin() + 1;
            int queryRight = upper_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), upperBoundVal) - sortedUniqueNums.begin();
            if (queryLeft <= queryRight) {
                totalInversions += queryTree(0, 1, treeSize, queryLeft, queryRight);
            }
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), num) - sortedUniqueNums.begin() + 1;
            updateTree(0, 1, treeSize, rankIndex, 1);
        }
        return totalInversions;
    }
public:
    int minThreshold(vector<int>& nums, long long k) {
        vector<int> sortedUniqueNums = nums;
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        int lowThreshold = 1, highThreshold = sortedUniqueNums.back() - sortedUniqueNums.front();
        int answer = -1;
        while (lowThreshold <= highThreshold) {
            int midThreshold = lowThreshold + (highThreshold - lowThreshold) / 2;
            if (countInversions(nums, sortedUniqueNums, midThreshold) >= k) {
                answer = midThreshold;
                highThreshold = midThreshold - 1;
            } else {
                lowThreshold = midThreshold + 1;
            }
        }
        return answer;
    }
};
