class Solution {
    struct SegmentTreeNode {
        int minValue;
        int maxValue;
        int lazyValue;
        SegmentTreeNode() : minValue(0), maxValue(0), lazyValue(0) {}
    };
    vector<SegmentTreeNode> segmentTree;
    int treeSize;

    void pushLazy(int nodeIndex) {
        if (segmentTree[nodeIndex].lazyValue != 0) {
            int lazyVal = segmentTree[nodeIndex].lazyValue;
            segmentTree[2 * nodeIndex + 1].minValue += lazyVal;
            segmentTree[2 * nodeIndex + 1].maxValue += lazyVal;
            segmentTree[2 * nodeIndex + 1].lazyValue += lazyVal;
            segmentTree[2 * nodeIndex + 2].minValue += lazyVal;
            segmentTree[2 * nodeIndex + 2].maxValue += lazyVal;
            segmentTree[2 * nodeIndex + 2].lazyValue += lazyVal;
            segmentTree[nodeIndex].lazyValue = 0;
        }
    }

    void updateRange(int nodeIndex, int left, int right, int queryLeft, int queryRight, int addValue) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            segmentTree[nodeIndex].minValue += addValue;
            segmentTree[nodeIndex].maxValue += addValue;
            segmentTree[nodeIndex].lazyValue += addValue;
            return;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        updateRange(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, addValue);
        updateRange(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, addValue);
        segmentTree[nodeIndex].minValue = min(segmentTree[2 * nodeIndex + 1].minValue, segmentTree[2 * nodeIndex + 2].minValue);
        segmentTree[nodeIndex].maxValue = max(segmentTree[2 * nodeIndex + 1].maxValue, segmentTree[2 * nodeIndex + 2].maxValue);
    }

    int findFirstZeroIndex(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return -1;
        }
        if (segmentTree[nodeIndex].minValue > 0 || segmentTree[nodeIndex].maxValue < 0) {
            return -1;
        }
        if (left == right) {
            return left;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        int leftResult = findFirstZeroIndex(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        if (leftResult != -1) {
            return leftResult;
        }
        return findFirstZeroIndex(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    int longestBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, SegmentTreeNode());
        unordered_map<int, int> lastSeenIndex;
        int maxSubarrayLength = 0;

        for (int right = 0; right < n; right++) {
            int currentNum = nums[right];
            int prevIndex = lastSeenIndex.count(currentNum) ? lastSeenIndex[currentNum] : -1;
            int changeValue = (currentNum % 2 == 0) ? 1 : -1;
            updateRange(0, 0, n - 1, prevIndex + 1, right, changeValue);
            lastSeenIndex[currentNum] = right;

            int firstZeroLeft = findFirstZeroIndex(0, 0, n - 1, 0, right);
            if (firstZeroLeft != -1) {
                maxSubarrayLength = max(maxSubarrayLength, right - firstZeroLeft + 1);
            }
        }

        return maxSubarrayLength;
    }
};
