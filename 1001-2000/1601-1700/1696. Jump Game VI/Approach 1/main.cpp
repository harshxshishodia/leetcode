class Solution {
    int solve(
        const vector<int>& nums,
        int k,
        int index
    ) {
        if (index == static_cast<int>(nums.size()) - 1) {
            return nums[index];
        }

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
                    next
                )
            );
        }

        return nums[index] + best;
    }

public:
    int maxResult(
        vector<int>& nums,
        int k
    ) {
        return solve(
            nums,
            k,
            0
        );
    }
};
