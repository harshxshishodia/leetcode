class Solution {
    int robRange(const vector<int>& nums, int left, int right) {
        int previous2 = 0;
        int previous1 = 0;

        for (int i = left; i <= right; i++) {
            int current = max(previous1, previous2 + nums[i]);
            previous2 = previous1;
            previous1 = current;
        }

        return previous1;
    }

public:
    int rob(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        if (n == 1) {
            return nums[0];
        }

        return max(
            robRange(nums, 0, n - 2),
            robRange(nums, 1, n - 1)
        );
    }
};
