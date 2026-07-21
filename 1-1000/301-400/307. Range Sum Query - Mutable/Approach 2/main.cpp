class NumArray {
    vector<int> nums;
    vector<int> prefix;

    void buildPrefix() {
        prefix[0] = 0;

        for (int index = 0; index < nums.size(); index++)
            prefix[index + 1] = prefix[index] + nums[index];
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        prefix.resize(nums.size() + 1);
        buildPrefix();
    }

    void update(int index, int val) {
        nums[index] = val;
        buildPrefix();
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};