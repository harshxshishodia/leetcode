class Solution {
    int solve(int nodes, vector<int>& dp) {
        if (nodes <= 1) {
            return 1;
        }

        if (dp[nodes] != -1) {
            return dp[nodes];
        }

        int answer = 0;

        for (int root = 1; root <= nodes; root++) {
            answer += solve(root - 1, dp) *
                      solve(nodes - root, dp);
        }

        dp[nodes] = answer;
        return dp[nodes];
    }

public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
