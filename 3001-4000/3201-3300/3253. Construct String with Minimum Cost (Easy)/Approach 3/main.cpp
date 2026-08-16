class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        const int INF = 1000000000;
        int n = static_cast<int>(target.size());
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int index = 0; index < n; index++) {
            if (dp[index] == INF) {
                continue;
            }

            for (int i = 0; i < static_cast<int>(words.size()); i++) {
                int length = static_cast<int>(words[i].size());

                if (index + length <= n &&
                    target.compare(index, length, words[i]) == 0) {
                    dp[index + length] = min(
                        dp[index + length],
                        dp[index] + costs[i]
                    );
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
