class Solution {
    vector<string> solve(
        int open,
        int close,
        int n,
        vector<vector<vector<string>>>& dp,
        vector<vector<bool>>& visited
    ) {
        if (open == n && close == n) {
            return {""};
        }

        if (visited[open][close]) {
            return dp[open][close];
        }

        visited[open][close] = true;
        vector<string> answer;

        if (open < n) {
            vector<string> suffixes = solve(open + 1, close, n, dp, visited);

            for (string& suffix : suffixes) {
                answer.push_back("(" + suffix);
            }
        }

        if (close < open) {
            vector<string> suffixes = solve(open, close + 1, n, dp, visited);

            for (string& suffix : suffixes) {
                answer.push_back(")" + suffix);
            }
        }

        dp[open][close] = answer;
        return dp[open][close];
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(
            n + 1,
            vector<vector<string>>(n + 1)
        );
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));

        return solve(0, 0, n, dp, visited);
    }
};
