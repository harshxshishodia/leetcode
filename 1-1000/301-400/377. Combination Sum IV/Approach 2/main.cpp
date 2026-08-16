class Solution {
    int solve(
        const vector<int>& nums,
        int remaining,
        vector<int>& memo
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (memo[remaining] != -1) {
            return memo[remaining];
        }

        unsigned long long answer = 0;

        for (int number : nums) {
            if (number <= remaining) {
                answer += solve(
                    nums,
                    remaining - number,
                    memo
                );
            }
        }

        memo[remaining] = static_cast<int>(answer);
        return memo[remaining];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        return solve(nums, target, memo);
    }
};
