class Solution {
public:
    int maximizeTheProfit(
        int n,
        vector<vector<int>>& offers
    ) {
        vector<vector<pair<int, int>>> ending(
            n
        );

        for (const vector<int>& offer :
             offers) {
            ending[
                offer[1]
            ].push_back({
                offer[0],
                offer[2]
            });
        }

        vector<int> dp(
            n + 1
        );

        for (int house = 0; house < n; house++) {
            dp[house + 1] =
                dp[house];

            for (auto [start, gold] :
                 ending[house]) {
                dp[house + 1] = max(
                    dp[house + 1],
                    dp[start] +
                    gold
                );
            }
        }

        return dp[n];
    }
};
