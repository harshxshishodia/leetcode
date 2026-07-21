class NumArray {
    vector<int> tree;
    int n;

    void build(const vector<int>& nums, int node, int left, int right) {
        if (left == right) {
            tree[node] = nums[left];
            return;
        }

        int middle = left + (right - left) / 2;
        build(nums, node * 2, left, middle);
        build(nums, node * 2 + 1, middle + 1, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void modify(int node, int left, int right, int index, int val) {
        if (left == right) {
            tree[node] = val;
            return;
        }

        int middle = left + (right - left) / 2;

        if (index <= middle)
            modify(node * 2, left, middle, index, val);
        else
            modify(node * 2 + 1, middle + 1, right, index, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft)
            return 0;

        if (queryLeft <= left && right <= queryRight)
            return tree[node];

        int middle = left + (right - left) / 2;
        return query(node * 2, left, middle, queryLeft, queryRight) + query(node * 2 + 1, middle + 1, right, queryLeft, queryRight);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, 0);
        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        modify(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};