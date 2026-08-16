class Solution {
    int solve(const vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int middle = left + (right - left) / 2;
        int leftAnswer = solve(nums, left, middle);
        int rightAnswer = solve(nums, middle + 1, right);

        int bestLeftSuffix = numeric_limits<int>::min();
        int sum = 0;

        for (int i = middle; i >= left; i--) {
            sum += nums[i];
            bestLeftSuffix = max(bestLeftSuffix, sum);
        }

        int bestRightPrefix = numeric_limits<int>::min();
        sum = 0;

        for (int i = middle + 1; i <= right; i++) {
            sum += nums[i];
            bestRightPrefix = max(bestRightPrefix, sum);
        }

        return max({
            leftAnswer,
            rightAnswer,
            bestLeftSuffix + bestRightPrefix
        });
    }

public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};
