class Solution {
    int solve(
        const string& s,
        int left,
        int right,
        vector<vector<int>>& memo
    ) {
        if (left > right) {
            return 0;
        }

        if (left == right) {
            return 1;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        if (s[left] == s[right]) {
            memo[left][right] =
                2 + solve(
                    s,
                    left + 1,
                    right - 1,
                    memo
                );
        } else {
            memo[left][right] = max(
                solve(
                    s,
                    left + 1,
                    right,
                    memo
                ),
                solve(
                    s,
                    left,
                    right - 1,
                    memo
                )
            );
        }

        return memo[left][right];
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> memo(
            n,
            vector<int>(n, -1)
        );

        return solve(s, 0, n - 1, memo);
    }
};
