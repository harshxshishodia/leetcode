class Solution {
    bool possible(
        const vector<int>& nums,
        int p,
        int limit
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> dp(
            n + 1
        );

        for (int index = 2; index <= n; index++) {
            dp[index] =
                dp[index - 1];

            if (nums[index - 1] -
                    nums[index - 2] <=
                limit) {
                dp[index] = max(
                    dp[index],
                    dp[index - 2] +
                    1
                );
            }
        }

        return dp[n] >= p;
    }

public:
    int minimizeMax(
        vector<int>& nums,
        int p
    ) {
        if (p == 0) {
            return 0;
        }

        sort(
            nums.begin(),
            nums.end()
        );

        int left = 0;

        int right =
            nums.back() -
            nums.front();

        while (left < right) {
            int middle =
                left +
                (right - left) /
                2;

            if (possible(
                    nums,
                    p,
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
