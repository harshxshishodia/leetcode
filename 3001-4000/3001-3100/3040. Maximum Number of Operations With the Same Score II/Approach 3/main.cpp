class Solution {
    int run(
        const vector<int>& nums,
        int score
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<vector<int>> dp(
            n,
            vector<int>(n)
        );

        for (int length = 2;
             length <= n;
             length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left +
                    length -
                    1;

                int answer = 0;

                if (nums[left] + nums[left + 1] == score) {
                    answer = max(
                        answer,
                        1 +
                        (
                            length > 2
                                ? dp[left + 2][right]
                                : 0
                        )
                    );
                }

                if (nums[right - 1] + nums[right] == score) {
                    answer = max(
                        answer,
                        1 +
                        (
                            length > 2
                                ? dp[left][right - 2]
                                : 0
                        )
                    );
                }

                if (nums[left] + nums[right] == score) {
                    answer = max(
                        answer,
                        1 +
                        (
                            length > 2
                                ? dp[left + 1][right - 1]
                                : 0
                        )
                    );
                }

                dp[left][right] =
                    answer;
            }
        }

        return dp[0][n - 1];
    }

public:
    int maxOperations(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        if (n < 2) {
            return 0;
        }

        return max({
            run(
                nums,
                nums[0] + nums[1]
            ),
            run(
                nums,
                nums[n - 2] + nums[n - 1]
            ),
            run(
                nums,
                nums[0] + nums[n - 1]
            )
        });
    }
};
