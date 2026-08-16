class Solution {
    static constexpr int MOD =
        1000000007;

    long long solve(
        const vector<int>& nums,
        int index,
        int parity
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return parity;
        }

        long long answer =
            solve(
                nums,
                index + 1,
                parity
            );

        answer +=
            solve(
                nums,
                index + 1,
                parity ^
                (nums[index] & 1)
            );

        return answer %
               MOD;
    }

public:
    int subsequenceCount(vector<int>& nums) {
        return static_cast<int>(
            solve(
                nums,
                0,
                0
            )
        );
    }
};
