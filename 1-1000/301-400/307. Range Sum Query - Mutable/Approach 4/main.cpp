class NumArray {
    vector<int> nums;
    vector<int> tree;

    void add(int index, int difference) {
        index++;

        while (index < tree.size()) {
            tree[index] += difference;
            index += index & -index;
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        index++;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        tree.assign(nums.size() + 1, 0);

        for (int index = 0; index < nums.size(); index++)
            add(index, nums[index]);
    }

    void update(int index, int val) {
        int difference = val - nums[index];
        nums[index] = val;
        add(index, difference);
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};