class Solution {
    int solve(
        const string& text1,
        const string& text2,
        int first,
        int second,
        vector<vector<int>>& memo
    ) {
        if (first == static_cast<int>(text1.size()) ||
            second == static_cast<int>(text2.size())) {
            return 0;
        }

        if (memo[first][second] != -1) {
            return memo[first][second];
        }

        if (text1[first] == text2[second]) {
            memo[first][second] =
                1 +
                solve(
                    text1,
                    text2,
                    first + 1,
                    second + 1,
                    memo
                );
        } else {
            memo[first][second] = max(
                solve(
                    text1,
                    text2,
                    first + 1,
                    second,
                    memo
                ),
                solve(
                    text1,
                    text2,
                    first,
                    second + 1,
                    memo
                )
            );
        }

        return memo[first][second];
    }

public:
    int longestCommonSubsequence(
        string text1,
        string text2
    ) {
        vector<vector<int>> memo(
            text1.size(),
            vector<int>(
                text2.size(),
                -1
            )
        );

        return solve(
            text1,
            text2,
            0,
            0,
            memo
        );
    }
};
