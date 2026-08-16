class NumArray {
    vector<int> fenwickTree;
    vector<int> originalNums;
    int size;

    void addDelta(int i, int delta) {
        for (; i <= size; i += i & (-i)) {
            fenwickTree[i] += delta;
        }
    }

    int queryPrefix(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i)) {
            sum += fenwickTree[i];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : originalNums(nums), size(static_cast<int>(nums.size())), fenwickTree(nums.size() + 1, 0) {
        for (int i = 0; i < size; i++) {
            addDelta(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - originalNums[index];
        originalNums[index] = val;
        addDelta(index + 1, delta);
    }

    int sumRange(int left, int right) {
        return queryPrefix(right + 1) - queryPrefix(left);
    }
};
