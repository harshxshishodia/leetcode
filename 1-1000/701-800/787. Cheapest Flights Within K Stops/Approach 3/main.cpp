class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        const int INF = 1000000000;

        vector<vector<int>> dp(
            k + 2,
            vector<int>(n, INF)
        );

        dp[0][src] = 0;

        for (int edges = 1; edges <= k + 1; edges++) {
            dp[edges] = dp[edges - 1];

            for (const vector<int>& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (dp[edges - 1][from] == INF) {
                    continue;
                }

                dp[edges][to] = min(
                    dp[edges][to],
                    dp[edges - 1][from] + price
                );
            }
        }

        return dp[k + 1][dst] == INF
            ? -1
            : dp[k + 1][dst];
    }
};
