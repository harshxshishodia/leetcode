class Solution {
    vector<int> leftSegmentTree;
    vector<int> rightSegmentTree;
    int treeSize;

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void updateTree(vector<int>& segmentTree, int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] += value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(segmentTree, 2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(const vector<int>& segmentTree, int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(segmentTree, 2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    int maxDistinctPrimes(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        treeSize = maxVal + 1;
        leftSegmentTree.assign(4 * treeSize, 0);
        rightSegmentTree.assign(4 * treeSize, 0);

        for (int x : nums) {
            if (isPrime(x)) {
                updateTree(rightSegmentTree, 0, 0, treeSize - 1, x, 1);
            }
        }

        int maxPrimes = 0;
        for (int i = 0; i < n - 1; i++) {
            if (isPrime(nums[i])) {
                updateTree(rightSegmentTree, 0, 0, treeSize - 1, nums[i], -1);
                updateTree(leftSegmentTree, 0, 0, treeSize - 1, nums[i], 1);
            }
            int leftPrimes = queryTree(leftSegmentTree, 0, 0, treeSize - 1, 0, treeSize - 1);
            int rightPrimes = queryTree(rightSegmentTree, 0, 0, treeSize - 1, 0, treeSize - 1);
            maxPrimes = max(maxPrimes, leftPrimes + rightPrimes);
        }

        return maxPrimes;
    }
};
