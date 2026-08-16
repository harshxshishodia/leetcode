class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {
            for (int leftNodes = 0; leftNodes < nodes; leftNodes++) {
                int rightNodes = nodes - 1 - leftNodes;
                dp[nodes] += dp[leftNodes] * dp[rightNodes];
            }
        }

        return dp[n];
    }
};
