class Solution {
    int target;
    vector<int> memo;

    bool solve(
        const vector<int>& nums,
        int mask,
        int currentSum
    ) {
        if (mask == (1 << nums.size()) - 1) {
            return currentSum == 0;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int bit = 1 << i;

            if ((mask & bit) != 0) {
                continue;
            }

            if (currentSum + nums[i] > target) {
                continue;
            }

            int nextSum =
                (currentSum + nums[i]) % target;

            if (solve(
                    nums,
                    mask | bit,
                    nextSum)) {
                return memo[mask] = 1;
            }
        }

        return memo[mask] = 0;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        if (total % k != 0) {
            return false;
        }

        target = total / k;

        if (*max_element(
                nums.begin(),
                nums.end()) > target) {
            return false;
        }

        memo.assign(
            1 << nums.size(),
            -1
        );

        return solve(
            nums,
            0,
            0
        );
    }
};
