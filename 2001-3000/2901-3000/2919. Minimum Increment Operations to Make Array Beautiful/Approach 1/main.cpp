class Solution {
    long long solve(
        const vector<int>& nums,
        int k,
        int index,
        int consecutiveLow
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return 0;
        }

        long long raise =
            max(
                0,
                k -
                nums[index]
            ) +
            solve(
                nums,
                k,
                index + 1,
                0
            );

        long long keep =
            numeric_limits<long long>::max() /
            4;

        if (nums[index] >= k) {
            keep =
                solve(
                    nums,
                    k,
                    index + 1,
                    0
                );
        } else if (consecutiveLow < 2) {
            keep =
                solve(
                    nums,
                    k,
                    index + 1,
                    consecutiveLow + 1
                );
        }

        return min(
            raise,
            keep
        );
    }

public:
    long long minIncrementOperations(
        vector<int>& nums,
        int k
    ) {
        return solve(
            nums,
            k,
            0,
            0
        );
    }
};
