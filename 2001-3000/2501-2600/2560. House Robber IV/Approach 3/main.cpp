class Solution {
    bool possible(
        const vector<int>& nums,
        int k,
        int capability
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> dp(
            n + 1
        );

        for (int index = 1; index <= n; index++) {
            dp[index] =
                dp[index - 1];

            if (nums[index - 1] <= capability) {
                int take =
                    1 +
                    (
                        index >= 2
                            ? dp[index - 2]
                            : 0
                    );

                dp[index] = max(
                    dp[index],
                    take
                );
            }
        }

        return dp[n] >= k;
    }

public:
    int minCapability(
        vector<int>& nums,
        int k
    ) {
        int left =
            *min_element(
                nums.begin(),
                nums.end()
            );

        int right =
            *max_element(
                nums.begin(),
                nums.end()
            );

        while (left < right) {
            int middle =
                left +
                (right - left) /
                2;

            if (possible(
                    nums,
                    k,
                    middle)) {
                right =
                    middle;
            } else {
                left =
                    middle + 1;
            }
        }

        return left;
    }
};
