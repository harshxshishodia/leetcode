class Solution {
public:
    int minArrayLength(
        vector<int>& nums,
        int k
    ) {
        for (int value : nums) {
            if (value == 0) {
                return 1;
            }
        }

        int n =
            static_cast<int>(nums.size());

        vector<int> dp(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index] =
                1 +
                dp[index + 1];

            long long product =
                nums[index];

            for (int end = index + 1;
                 end < n;
                 end++) {
                if (product >
                    k /
                    nums[end]) {
                    break;
                }

                product *=
                    nums[end];

                dp[index] = min(
                    dp[index],
                    1 +
                    dp[end + 1]
                );
            }
        }

        return dp[0];
    }
};
