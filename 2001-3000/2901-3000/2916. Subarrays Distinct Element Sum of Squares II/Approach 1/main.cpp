class Solution {
    struct Node {
        long long sumX2;
        long long sumX;
        long long lazyAdd;
        Node() : sumX2(0), sumX(0), lazyAdd(0) {}
    };
    vector<Node> segmentTree;
    int treeSize;
    const long long modVal = 1000000007;

    void pushLazy(int nodeIndex, int left, int right) {
        if (segmentTree[nodeIndex].lazyAdd != 0) {
            long long val = segmentTree[nodeIndex].lazyAdd;
            int mid = left + (right - left) / 2;

            int leftChild = 2 * nodeIndex + 1;
            int rightChild = 2 * nodeIndex + 2;

            long long leftLen = mid - left + 1;
            segmentTree[leftChild].sumX2 = (segmentTree[leftChild].sumX2 + 2 * val * segmentTree[leftChild].sumX + val * val % modVal * leftLen) % modVal;
            segmentTree[leftChild].sumX = (segmentTree[leftChild].sumX + val * leftLen) % modVal;
            segmentTree[leftChild].lazyAdd = (segmentTree[leftChild].lazyAdd + val) % modVal;

            long long rightLen = right - mid;
            segmentTree[rightChild].sumX2 = (segmentTree[rightChild].sumX2 + 2 * val * segmentTree[rightChild].sumX + val * val % modVal * rightLen) % modVal;
            segmentTree[rightChild].sumX = (segmentTree[rightChild].sumX + val * rightLen) % modVal;
            segmentTree[rightChild].lazyAdd = (segmentTree[rightChild].lazyAdd + val) % modVal;

            segmentTree[nodeIndex].lazyAdd = 0;
        }
    }

    void updateRangeAdd(int nodeIndex, int left, int right, int queryLeft, int queryRight, long long val) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            long long len = right - left + 1;
            segmentTree[nodeIndex].sumX2 = (segmentTree[nodeIndex].sumX2 + 2 * val * segmentTree[nodeIndex].sumX + val * val % modVal * len) % modVal;
            segmentTree[nodeIndex].sumX = (segmentTree[nodeIndex].sumX + val * len) % modVal;
            segmentTree[nodeIndex].lazyAdd = (segmentTree[nodeIndex].lazyAdd + val) % modVal;
            return;
        }
        pushLazy(nodeIndex, left, right);
        int mid = left + (right - left) / 2;
        updateRangeAdd(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, val);
        updateRangeAdd(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, val);
        segmentTree[nodeIndex].sumX2 = (segmentTree[2 * nodeIndex + 1].sumX2 + segmentTree[2 * nodeIndex + 2].sumX2) % modVal;
        segmentTree[nodeIndex].sumX = (segmentTree[2 * nodeIndex + 1].sumX + segmentTree[2 * nodeIndex + 2].sumX) % modVal;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, Node());

        unordered_map<int, int> lastSeenMap;
        long long totalSumOfSquares = 0;

        for (int r = 0; r < n; r++) {
            int prevIndex = lastSeenMap.count(nums[r]) ? lastSeenMap[nums[r]] : -1;
            updateRangeAdd(0, 0, n - 1, prevIndex + 1, r, 1);
            lastSeenMap[nums[r]] = r;
            totalSumOfSquares = (totalSumOfSquares + segmentTree[0].sumX2) % modVal;
        }

        return totalSumOfSquares;
    }
};
