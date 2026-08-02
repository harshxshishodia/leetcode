class Solution {
    vector<int> segmentTree;
    int treeSize;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums) {
        if (left == right) {
            segmentTree[nodeIndex] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums);
        segmentTree[nodeIndex] = gcd(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
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
        segmentTree[nodeIndex] = gcd(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return gcd(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    vector<bool> goodSubsequenceQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, nums);

        vector<bool> resultAnswers;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                updateTree(0, 0, n - 1, q[1], q[2]);
            } else if (type == 2) {
                int rangeGcd = queryTree(0, 0, n - 1, q[1], q[2]);
                resultAnswers.push_back(rangeGcd == 1);
            }
        }
        return resultAnswers;
    }
};
