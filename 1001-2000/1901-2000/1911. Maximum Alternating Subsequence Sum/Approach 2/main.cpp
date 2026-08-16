class Solution {
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(
        const vector<int>& nums,
        int index,
        int parity
    ) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        if (visited[index][parity]) {
            return memo[index][parity];
        }

        visited[index][parity] = true;

        long long skip =
            solve(
                nums,
                index + 1,
                parity
            );

        long long take =
            (
                parity == 0
                    ? nums[index]
                    : -nums[index]
            ) +
            solve(
                nums,
                index + 1,
                parity ^ 1
            );

        memo[index][parity] = max(
            skip,
            take
        );

        return memo[index][parity];
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        memo.assign(
            nums.size(),
            {}
        );

        visited.assign(
            nums.size(),
            {}
        );

        return solve(
            nums,
            0,
            0
        );
    }
};
