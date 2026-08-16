class Solution {
    vector<int> memo;

    int solve(
        const vector<int>& nums,
        int index
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n) {
            return 1;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        bool answer = false;

        if (index + 1 < n &&
            nums[index] ==
            nums[index + 1]) {
            answer =
                solve(
                    nums,
                    index + 2
                );
        }

        if (!answer &&
            index + 2 < n) {
            bool tripleEqual =
                nums[index] ==
                    nums[index + 1] &&
                nums[index + 1] ==
                    nums[index + 2];

            bool consecutive =
                nums[index] + 1 ==
                    nums[index + 1] &&
                nums[index + 1] + 1 ==
                    nums[index + 2];

            if (tripleEqual ||
                consecutive) {
                answer =
                    solve(
                        nums,
                        index + 3
                    );
            }
        }

        memo[index] =
            answer;

        return memo[index];
    }

public:
    bool validPartition(vector<int>& nums) {
        memo.assign(
            nums.size(),
            -1
        );

        return solve(
            nums,
            0
        );
    }
};
