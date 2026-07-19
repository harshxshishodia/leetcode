class Solution {
    struct Result {
        int totalSum;
        int maximumPrefix;
        int maximumSuffix;
        int maximumSubarray;
    };

    Result mergeResults(const Result& left, const Result& right) {
        Result result;
        result.totalSum = left.totalSum + right.totalSum;
        result.maximumPrefix = max(left.maximumPrefix, left.totalSum + right.maximumPrefix);
        result.maximumSuffix = max(right.maximumSuffix, right.totalSum + left.maximumSuffix);
        result.maximumSubarray = max(max(left.maximumSubarray, right.maximumSubarray), left.maximumSuffix + right.maximumPrefix);
        return result;
    }

    Result solve(const vector<int>& nums, int left, int right) {
        if (left == right)
            return {nums[left], nums[left], nums[left], nums[left]};

        int middle = left + (right - left) / 2;
        Result leftResult = solve(nums, left, middle);
        Result rightResult = solve(nums, middle + 1, right);
        return mergeResults(leftResult, rightResult);
    }

public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1).maximumSubarray;
    }
};