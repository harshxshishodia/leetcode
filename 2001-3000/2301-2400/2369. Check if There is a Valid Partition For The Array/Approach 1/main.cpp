class Solution {
    bool solve(
        const vector<int>& nums,
        int index
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n) {
            return true;
        }

        if (index + 1 < n &&
            nums[index] ==
            nums[index + 1] &&
            solve(
                nums,
                index + 2
            )) {
            return true;
        }

        if (index + 2 < n) {
            if (nums[index] ==
                    nums[index + 1] &&
                nums[index + 1] ==
                    nums[index + 2] &&
                solve(
                    nums,
                    index + 3
                )) {
                return true;
            }

            if (nums[index] + 1 ==
                    nums[index + 1] &&
                nums[index + 1] + 1 ==
                    nums[index + 2] &&
                solve(
                    nums,
                    index + 3
                )) {
                return true;
            }
        }

        return false;
    }

public:
    bool validPartition(vector<int>& nums) {
        return solve(
            nums,
            0
        );
    }
};
