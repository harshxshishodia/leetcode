class Solution {
    int solve(
        const string& first,
        const string& second,
        int i,
        int j,
        vector<vector<int>>& memo
    ) {
        if (i == static_cast<int>(first.size())) {
            return static_cast<int>(second.size()) - j;
        }

        if (j == static_cast<int>(second.size())) {
            return static_cast<int>(first.size()) - i;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (first[i] == second[j]) {
            memo[i][j] = solve(
                first,
                second,
                i + 1,
                j + 1,
                memo
            );
        } else {
            memo[i][j] = 1 + min(
                solve(
                    first,
                    second,
                    i + 1,
                    j,
                    memo
                ),
                solve(
                    first,
                    second,
                    i,
                    j + 1,
                    memo
                )
            );
        }

        return memo[i][j];
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(
            word1.size(),
            vector<int>(word2.size(), -1)
        );

        return solve(
            word1,
            word2,
            0,
            0,
            memo
        );
    }
};
