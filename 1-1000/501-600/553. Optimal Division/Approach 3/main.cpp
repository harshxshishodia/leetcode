class Solution {
    struct State {
        long double minimum;
        long double maximum;
        string minimumExpression;
        string maximumExpression;
    };

public:
    string optimalDivision(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<vector<State>> dp(
            n,
            vector<State>(n)
        );

        for (int i = 0; i < n; i++) {
            string value = to_string(nums[i]);

            dp[i][i] = {
                static_cast<long double>(nums[i]),
                static_cast<long double>(nums[i]),
                value,
                value
            };
        }

        for (int length = 2; length <= n; length++) {
            for (int left = 0; left + length <= n; left++) {
                int right = left + length - 1;

                dp[left][right] = {
                    numeric_limits<long double>::infinity(),
                    -numeric_limits<long double>::infinity(),
                    "",
                    ""
                };

                for (int split = left; split < right; split++) {
                    const State& first = dp[left][split];
                    const State& second = dp[split + 1][right];

                    long double maximumValue =
                        first.maximum / second.minimum;

                    long double minimumValue =
                        first.minimum / second.maximum;

                    string maximumRight =
                        split + 1 < right
                            ? "(" + second.minimumExpression + ")"
                            : second.minimumExpression;

                    string minimumRight =
                        split + 1 < right
                            ? "(" + second.maximumExpression + ")"
                            : second.maximumExpression;

                    if (maximumValue > dp[left][right].maximum) {
                        dp[left][right].maximum = maximumValue;
                        dp[left][right].maximumExpression =
                            first.maximumExpression +
                            "/" +
                            maximumRight;
                    }

                    if (minimumValue < dp[left][right].minimum) {
                        dp[left][right].minimum = minimumValue;
                        dp[left][right].minimumExpression =
                            first.minimumExpression +
                            "/" +
                            minimumRight;
                    }
                }
            }
        }

        return dp[0][n - 1].maximumExpression;
    }
};
