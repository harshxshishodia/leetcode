class NumArray {
    vector<int> nums;
    vector<int> blocks;
    int blockSize;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        blockSize = sqrt(nums.size()) + 1;
        blocks.assign(blockSize, 0);

        for (int index = 0; index < nums.size(); index++)
            blocks[index / blockSize] += nums[index];
    }

    void update(int index, int val) {
        blocks[index / blockSize] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;

        while (left <= right && left % blockSize != 0) {
            sum += nums[left];
            left++;
        }

        while (left + blockSize - 1 <= right) {
            sum += blocks[left / blockSize];
            left += blockSize;
        }

        while (left <= right) {
            sum += nums[left];
            left++;
        }

        return sum;
    }
};