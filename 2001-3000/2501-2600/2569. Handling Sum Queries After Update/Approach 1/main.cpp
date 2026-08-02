class Solution {
    vector<long long> segmentTree;
    vector<int> lazyFlip;
    int treeSize;

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums1) {
        if (left == right) {
            segmentTree[nodeIndex] = nums1[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums1);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums1);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    void pushLazy(int nodeIndex, int left, int right) {
        if (lazyFlip[nodeIndex] == 1) {
            int mid = left + (right - left) / 2;
            segmentTree[2 * nodeIndex + 1] = (mid - left + 1) - segmentTree[2 * nodeIndex + 1];
            lazyFlip[2 * nodeIndex + 1] ^= 1;
            segmentTree[2 * nodeIndex + 2] = (right - mid) - segmentTree[2 * nodeIndex + 2];
            lazyFlip[2 * nodeIndex + 2] ^= 1;
            lazyFlip[nodeIndex] = 0;
        }
    }

    void updateRangeFlip(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            segmentTree[nodeIndex] = (right - left + 1) - segmentTree[nodeIndex];
            lazyFlip[nodeIndex] ^= 1;
            return;
        }
        pushLazy(nodeIndex, left, right);
        int mid = left + (right - left) / 2;
        updateRangeFlip(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        updateRangeFlip(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        lazyFlip.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, nums1);

        long long currentSumNums2 = 0;
        for (int num : nums2) {
            currentSumNums2 += num;
        }

        vector<long long> resultAnswers;
        for (const auto& query : queries) {
            int type = query[0];
            if (type == 1) {
                updateRangeFlip(0, 0, n - 1, query[1], query[2]);
            } else if (type == 2) {
                currentSumNums2 += (long long)query[1] * segmentTree[0];
            } else if (type == 3) {
                resultAnswers.push_back(currentSumNums2);
            }
        }
        return resultAnswers;
    }
};
