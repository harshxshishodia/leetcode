class Solution {
    vector<int> segmentTree;
    int treeSize;
    void buildTree(int nodeIndex, int left, int right, const vector<int>& arr) {
        if (left == right) {
            segmentTree[nodeIndex] = arr[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, arr);
        buildTree(2 * nodeIndex + 2, mid + 1, right, arr);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] & segmentTree[2 * nodeIndex + 2];
    }
    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return -1; // -1 has all bits set (111...1)
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
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, arr);
        int minDifference = INT_MAX;
        for (int i = 0; i < n; i++) {
            int lowIndex = i, highIndex = n - 1;
            while (lowIndex <= highIndex) {
                int midIndex = lowIndex + (highIndex - lowIndex) / 2;
                int currentAnd = queryTree(0, 0, n - 1, i, midIndex);
                minDifference = min(minDifference, abs(currentAnd - target));
                if (currentAnd >= target) {
                    lowIndex = midIndex + 1;
                } else {
                    highIndex = midIndex - 1;
                }
            }
        }
        return minDifference;
    }
};
