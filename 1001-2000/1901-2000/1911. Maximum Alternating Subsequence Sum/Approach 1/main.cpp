class Solution {
    long long solve(
        const vector<int>& nums,
        int index,
        int parity
    ) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

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

        return max(
            skip,
            take
        );
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        return solve(
            nums,
            0,
            0
        );
    }
};
