class Solution {
    static constexpr int NEG =
        -1000000000;

    int solve(
        const vector<int>& nums,
        int index,
        int remaining
    ) {
        if (remaining == 0) {
            return 0;
        }

        if (index ==
            static_cast<int>(nums.size())) {
            return NEG;
        }

        int skip =
            solve(
                nums,
                index + 1,
                remaining
            );

        int take =
            NEG;

        if (nums[index] <= remaining) {
            int next =
                solve(
                    nums,
                    index + 1,
                    remaining -
                    nums[index]
                );

            if (next != NEG) {
                take =
                    1 +
                    next;
            }
        }

        return max(
            skip,
            take
        );
    }

public:
    int lengthOfLongestSubsequence(
        vector<int>& nums,
        int target
    ) {
        int answer =
            solve(
                nums,
                0,
                target
            );

        return answer < 0
            ? -1
            : answer;
    }
};
