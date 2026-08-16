class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n =
            static_cast<int>(questions.size());

        vector<long long> dp(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            int next = min(
                n,
                index +
                questions[index][1] +
                1
            );

            dp[index] = max(
                dp[index + 1],
                questions[index][0] +
                dp[next]
            );
        }

        return dp[0];
    }
};
