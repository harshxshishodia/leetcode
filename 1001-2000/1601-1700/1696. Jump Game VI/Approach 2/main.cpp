class Solution {
    int solve(
        const vector<int>& nums,
        int k,
        int index,
        vector<int>& memo,
        vector<bool>& visited
    ) {
        if (index == static_cast<int>(nums.size()) - 1) {
            return nums[index];
        }

        if (visited[index]) {
            return memo[index];
        }

        visited[index] = true;

        int best =
            numeric_limits<int>::min();

        for (int next = index + 1;
             next < static_cast<int>(nums.size()) &&
             next <= index + k;
             next++) {
            best = max(
                best,
                solve(
                    nums,
                    k,
                    next,
                    memo,
                    visited
                )
            );
        }

        memo[index] =
            nums[index] +
            best;

        return memo[index];
    }

public:
    int maxResult(
        vector<int>& nums,
        int k
    ) {
        vector<int> memo(
            nums.size()
        );

        vector<bool> visited(
            nums.size()
        );

        return solve(
            nums,
            k,
            0,
            memo,
            visited
        );
    }
};
