class Solution {
public:
    bool validPartition(vector<int>& nums) {
        array<bool, 4> dp = {};
        dp[0] = true;

        int n =
            static_cast<int>(nums.size());

        for (int length = 1;
             length <= n;
             length++) {
            bool current = false;

            if (length >= 2 &&
                dp[(length - 2) % 4] &&
                nums[length - 2] ==
                nums[length - 1]) {
                current = true;
            }

            if (length >= 3 &&
                dp[(length - 3) % 4]) {
                bool tripleEqual =
                    nums[length - 3] ==
                        nums[length - 2] &&
                    nums[length - 2] ==
                        nums[length - 1];

                bool consecutive =
                    nums[length - 3] + 1 ==
                        nums[length - 2] &&
                    nums[length - 2] + 1 ==
                        nums[length - 1];

                current =
                    current ||
                    tripleEqual ||
                    consecutive;
            }

            dp[length % 4] =
                current;
        }

        return dp[n % 4];
    }
};
