class Solution {
    vector<long long> evenSegmentTree;
    vector<long long> oddSegmentTree;
    int treeSize;

    void updateTree(vector<long long>& segmentTree, int nodeIndex, int left, int right, int updateIndex, long long value) {
        if (left == right) {
            segmentTree[nodeIndex] = max(segmentTree[nodeIndex], value);
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(segmentTree, 2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    long long queryTree(const vector<long long>& segmentTree, int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return LLONG_MIN / 2;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return max(queryTree(segmentTree, 2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        treeSize = n;
        evenSegmentTree.assign(4 * treeSize, LLONG_MIN / 2);
        oddSegmentTree.assign(4 * treeSize, LLONG_MIN / 2);

        long long overallMaxSum = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                int prevIdx = i - k;
                long long bestEvenPrev = queryTree(evenSegmentTree, 0, 0, n - 1, prevIdx, prevIdx);
                long long bestOddPrev = queryTree(oddSegmentTree, 0, 0, n - 1, prevIdx, prevIdx);
            }

            long long maxPrevEven = (i >= k) ? queryTree(evenSegmentTree, 0, 0, n - 1, 0, i - k) : (LLONG_MIN / 2);
            long long maxPrevOdd = (i >= k) ? queryTree(oddSegmentTree, 0, 0, n - 1, 0, i - k) : (LLONG_MIN / 2);

            long long dpOdd = nums[i] + max(0LL, maxPrevEven);
            long long dpEven = -nums[i] + maxPrevOdd;

            overallMaxSum = max({overallMaxSum, dpOdd, dpEven});

            updateTree(oddSegmentTree, 0, 0, n - 1, i, dpOdd);
            updateTree(evenSegmentTree, 0, 0, n - 1, i, dpEven);
        }

        return overallMaxSum;
    }
};
