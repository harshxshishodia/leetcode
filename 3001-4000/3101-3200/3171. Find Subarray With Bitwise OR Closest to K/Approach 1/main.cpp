class Solution {
    vector<int> segmentTree;
    int treeSize;

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums) {
        if (left == right) {
            segmentTree[nodeIndex] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] | segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) |
               queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, nums);

        int minDifference = INT_MAX;

        for (int i = 0; i < n; i++) {
            int lowIndex = i, highIndex = n - 1;
            while (lowIndex <= highIndex) {
                int midIndex = lowIndex + (highIndex - lowIndex) / 2;
                int currentOr = queryTree(0, 0, n - 1, i, midIndex);
                minDifference = min(minDifference, abs(currentOr - k));
                if (currentOr < k) {
                    lowIndex = midIndex + 1;
                } else {
                    highIndex = midIndex - 1;
                }
            }
        }

        return minDifference;
    }
};
