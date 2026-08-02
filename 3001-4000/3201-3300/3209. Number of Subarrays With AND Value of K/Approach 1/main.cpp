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
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] & segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return -1;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        int leftAnd = queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        int rightAnd = queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        if (leftAnd == -1) return rightAnd;
        if (rightAnd == -1) return leftAnd;
        return leftAnd & rightAnd;
    }

public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, -1);
        buildTree(0, 0, n - 1, nums);

        long long totalCount = 0;

        for (int i = 0; i < n; i++) {
            // First index where AND <= k
            int low1 = i, high1 = n - 1, firstIndex = -1;
            while (low1 <= high1) {
                int mid1 = low1 + (high1 - low1) / 2;
                int currentAnd = queryTree(0, 0, n - 1, i, mid1);
                if (currentAnd <= k) {
                    if (currentAnd == k) firstIndex = mid1;
                    high1 = mid1 - 1;
                } else {
                    low1 = mid1 + 1;
                }
            }

            // Last index where AND >= k
            int low2 = i, high2 = n - 1, lastIndex = -1;
            while (low2 <= high2) {
                int mid2 = low2 + (high2 - low2) / 2;
                int currentAnd = queryTree(0, 0, n - 1, i, mid2);
                if (currentAnd >= k) {
                    if (currentAnd == k) lastIndex = mid2;
                    low2 = mid2 + 1;
                } else {
                    high2 = mid2 - 1;
                }
            }

            if (firstIndex != -1 && lastIndex != -1 && firstIndex <= lastIndex) {
                totalCount += (lastIndex - firstIndex + 1);
            }
        }

        return totalCount;
    }
};
