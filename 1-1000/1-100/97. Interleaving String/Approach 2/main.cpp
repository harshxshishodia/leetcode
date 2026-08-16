class Solution {
    int solve(
        const string& first,
        const string& second,
        const string& target,
        int i,
        int j,
        vector<vector<int>>& dp
    ) {
        int k = i + j;

        if (k == static_cast<int>(target.size())) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool possible = false;

        if (i < static_cast<int>(first.size()) &&
            first[i] == target[k]) {
            possible = solve(first, second, target, i + 1, j, dp);
        }

        if (!possible &&
            j < static_cast<int>(second.size()) &&
            second[j] == target[k]) {
            possible = solve(first, second, target, i, j + 1, dp);
        }

        dp[i][j] = possible;
        return dp[i][j];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return solve(s1, s2, s3, 0, 0, dp);
    }
};
