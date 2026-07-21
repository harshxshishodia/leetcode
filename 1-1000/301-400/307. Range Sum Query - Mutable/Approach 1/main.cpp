class NumArray {
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }

    void update(int index, int val) {
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;

        for (int index = left; index <= right; index++)
            sum += nums[index];

        return sum;
    }
};