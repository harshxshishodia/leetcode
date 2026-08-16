class Solution {
    int solve(
        const string& first,
        const string& second,
        int i,
        int j,
        vector<vector<int>>& dp
    ) {
        if (i == static_cast<int>(first.size())) {
            return static_cast<int>(second.size()) - j;
        }

        if (j == static_cast<int>(second.size())) {
            return static_cast<int>(first.size()) - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (first[i] == second[j]) {
            dp[i][j] = solve(first, second, i + 1, j + 1, dp);
        } else {
            int insertCost = solve(first, second, i, j + 1, dp);
            int deleteCost = solve(first, second, i + 1, j, dp);
            int replaceCost = solve(first, second, i + 1, j + 1, dp);
            dp[i][j] = 1 + min({insertCost, deleteCost, replaceCost});
        }

        return dp[i][j];
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(
            word1.size(),
            vector<int>(word2.size(), -1)
        );

        return solve(word1, word2, 0, 0, dp);
    }
};
