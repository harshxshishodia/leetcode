class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n =
            static_cast<int>(prices.size());

        vector<int> dp(
            n + 1
        );

        deque<int> candidates;

        for (int index = n - 1;
             index >= 0;
             index--) {
            int right =
                min(
                    n,
                    2 *
                    index +
                    2
                );

            while (
                !candidates.empty() &&
                candidates.front() >
                right
            ) {
                candidates.pop_front();
            }

            int nextIndex =
                index +
                1;

            while (
                !candidates.empty() &&
                dp[candidates.back()] >=
                dp[nextIndex]
            ) {
                candidates.pop_back();
            }

            candidates.push_back(
                nextIndex
            );

            dp[index] =
                prices[index] +
                dp[candidates.front()];
        }

        return dp[0];
    }
};
