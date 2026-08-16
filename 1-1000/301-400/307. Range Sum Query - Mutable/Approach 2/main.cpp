class NumArray {
    vector<int> segmentTree;
    int n;

    void buildTree(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            segmentTree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * node, start, mid);
        buildTree(nums, 2 * node + 1, mid + 1, end);
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }

    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            segmentTree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid) {
            updateTree(2 * node, start, mid, index, val);
        } else {
            updateTree(2 * node + 1, mid + 1, end, index, val);
        }
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }

    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return segmentTree[node];
        int mid = start + (end - start) / 2;
        return queryTree(2 * node, start, mid, l, r) + queryTree(2 * node + 1, mid + 1, end, l, r);
    }

public:
    NumArray(vector<int>& nums) : n(static_cast<int>(nums.size())), segmentTree(4 * nums.size(), 0) {
        buildTree(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(1, 0, n - 1, left, right);
    }
};
