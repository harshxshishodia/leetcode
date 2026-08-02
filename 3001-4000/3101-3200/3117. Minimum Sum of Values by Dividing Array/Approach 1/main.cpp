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
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, -1);
        buildTree(0, 0, n - 1, nums);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[0][0] = 0;

        for (int j = 1; j <= m; j++) {
            int targetAnd = andValues[j - 1];
            for (int i = 1; i <= n; i++) {
                // Find valid range of prev indices
                int lowL = 0, highL = i - 1, firstValid = -1, lastValid = -1;
                while (lowL <= highL) {
                    int midL = lowL + (highL - lowL) / 2;
                    int curAnd = queryTree(0, 0, n - 1, midL, i - 1);
                    if (curAnd <= targetAnd) {
                        if (curAnd == targetAnd) firstValid = midL;
                        highL = midL - 1;
                    } else {
                        lowL = midL + 1;
                    }
                }
                lowL = 0; highL = i - 1;
                while (lowL <= highL) {
                    int midL = lowL + (highL - lowL) / 2;
                    int curAnd = queryTree(0, 0, n - 1, midL, i - 1);
                    if (curAnd >= targetAnd) {
                        if (curAnd == targetAnd) lastValid = midL;
                        lowL = midL + 1;
                    } else {
                        highL = midL - 1;
                    }
                }
                if (firstValid != -1 && lastValid != -1 && firstValid <= lastValid) {
                    for (int k = firstValid; k <= lastValid; k++) {
                        dp[j][i] = min(dp[j][i], dp[j - 1][k] + nums[i - 1]);
                    }
                }
            }
        }

        return dp[m][n] >= INT_MAX / 2 ? -1 : dp[m][n];
    }
};
