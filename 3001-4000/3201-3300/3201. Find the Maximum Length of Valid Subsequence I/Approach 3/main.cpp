class Solution {
public:
    int maximumLength(vector<int>& nums) {
        array<array<int, 2>, 2> dp = {};

        int answer = 1;

        for (int value : nums) {
            int current =
                value &
                1;

            for (int target = 0;
                 target <= 1;
                 target++) {
                int previous =
                    (
                        target -
                        current +
                        2
                    ) %
                    2;

                int candidate =
                    max(
                        1,
                        dp[target][previous] +
                        1
                    );

                dp[target][current] = max(
                    dp[target][current],
                    candidate
                );

                answer = max(
                    answer,
                    dp[target][current]
                );
            }
        }

        return answer;
    }
};
