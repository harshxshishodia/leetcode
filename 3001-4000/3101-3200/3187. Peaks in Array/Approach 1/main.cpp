class Solution {
    vector<int> segmentTree;
    int treeSize;

    bool isPeak(const vector<int>& nums, int i) {
        if (i <= 0 || i >= (int)nums.size() - 1) return false;
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums) {
        if (left == right) {
            segmentTree[nodeIndex] = isPeak(nums, left) ? 1 : 0;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, nums);

        vector<int> resultAnswers;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int l = q[1];
                int r = q[2];
                if (r - l < 2) {
                    resultAnswers.push_back(0);
                } else {
                    resultAnswers.push_back(queryTree(0, 0, n - 1, l + 1, r - 1));
                }
            } else if (type == 2) {
                int index = q[1];
                int val = q[2];
                nums[index] = val;

                for (int pos = max(0, index - 1); pos <= min(n - 1, index + 1); pos++) {
                    updateTree(0, 0, n - 1, pos, isPeak(nums, pos) ? 1 : 0);
                }
            }
        }

        return resultAnswers;
    }
};
