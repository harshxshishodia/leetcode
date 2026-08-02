class Solution {
    vector<long long> segmentTreeSum;
    vector<int> segmentTreeCount;
    int treeSize;

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int val, int countVal) {
        if (left == right) {
            segmentTreeSum[nodeIndex] += (long long)val * countVal;
            segmentTreeCount[nodeIndex] += countVal;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, val, countVal);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, val, countVal);
        }
        segmentTreeSum[nodeIndex] = segmentTreeSum[2 * nodeIndex + 1] + segmentTreeSum[2 * nodeIndex + 2];
        segmentTreeCount[nodeIndex] = segmentTreeCount[2 * nodeIndex + 1] + segmentTreeCount[2 * nodeIndex + 2];
    }

public:
    long long minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sortedUniqueNums = nums;
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        treeSize = sortedUniqueNums.size();

        segmentTreeSum.assign(4 * treeSize, 0);
        segmentTreeCount.assign(4 * treeSize, 0);

        long long minOps = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i]) - sortedUniqueNums.begin() + 1;
            updateTree(0, 1, treeSize, rankIndex, nums[i], 1);

            if (i >= k - 1) {
                if (i >= k) {
                    int prevRank = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i - k]) - sortedUniqueNums.begin() + 1;
                    updateTree(0, 1, treeSize, prevRank, nums[i - k], -1);
                }
                long long currentSum = segmentTreeSum[0];
                long long medianVal = currentSum / k;
                minOps = min(minOps, abs(currentSum - medianVal * k));
            }
        }

        return minOps == LLONG_MAX ? 0 : minOps;
    }
};
