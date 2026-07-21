class NumArray {
    vector<int> tree;
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(2 * n, 0);

        for (int index = 0; index < n; index++)
            tree[n + index] = nums[index];

        for (int index = n - 1; index > 0; index--)
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }

    void update(int index, int val) {
        index += n;
        tree[index] = val;

        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;

        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left++;
            }

            if (right % 2 == 0) {
                sum += tree[right];
                right--;
            }

            left /= 2;
            right /= 2;
        }

        return sum;
    }
};