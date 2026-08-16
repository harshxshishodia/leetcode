class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n =
            static_cast<int>(prices.size());

        vector<long long> dp(
            n,
            1
        );

        long long answer = 1;

        for (int index = 1; index < n; index++) {
            if (prices[index - 1] -
                prices[index] == 1) {
                dp[index] =
                    dp[index - 1] +
                    1;
            }

            answer +=
                dp[index];
        }

        return answer;
    }
};
