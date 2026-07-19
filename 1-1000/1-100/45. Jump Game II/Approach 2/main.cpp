class Solution {
    vector<int> memo;

    int solve(const vector<int>& nums, int index) {
        if (index >= nums.size() - 1)
            return 0;

        if (memo[index] != -1)
            return memo[index];

        int minimumJumps = INT_MAX;

        for (int jumpLength = 1; jumpLength <= nums[index] && index + jumpLength < nums.size(); jumpLength++) {
            int jumps = solve(nums, index + jumpLength);

            if (jumps != INT_MAX)
                minimumJumps = min(minimumJumps, jumps + 1);
        }

        return memo[index] = minimumJumps;
    }

public:
    int jump(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};