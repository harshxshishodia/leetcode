class Solution {
    int solve(const vector<int>& nums, int index) {
        if (index >= nums.size() - 1)
            return 0;

        int minimumJumps = INT_MAX;

        for (int jumpLength = 1; jumpLength <= nums[index] && index + jumpLength < nums.size(); jumpLength++) {
            int jumps = solve(nums, index + jumpLength);

            if (jumps != INT_MAX)
                minimumJumps = min(minimumJumps, jumps + 1);
        }

        return minimumJumps;
    }

public:
    int jump(vector<int>& nums) {
        return solve(nums, 0);
    }
};