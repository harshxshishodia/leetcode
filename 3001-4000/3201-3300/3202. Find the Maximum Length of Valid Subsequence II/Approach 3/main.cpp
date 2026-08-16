class Solution {
public:
    int maximumLength(
        vector<int>& nums,
        int k
    ) {
        vector<vector<int>> dp(
            k,
            vector<int>(
                k
            )
        );

        int answer = 1;

        for (int value : nums) {
            int current =
                value %
                k;

            vector<int> previousColumn(
                k
            );

            for (int other = 0;
                 other < k;
                 other++) {
                previousColumn[other] =
                    dp[other][current];
            }

            for (int other = 0;
                 other < k;
                 other++) {
                dp[current][other] = max(
                    dp[current][other],
                    previousColumn[other] +
                    1
                );

                answer = max(
                    answer,
                    dp[current][other]
                );
            }
        }

        return answer;
    }
};
