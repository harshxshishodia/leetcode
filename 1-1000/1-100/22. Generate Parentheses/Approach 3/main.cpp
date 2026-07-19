class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");

        for (int pairs = 1; pairs <= n; pairs++) {
            for (int leftPairs = 0; leftPairs < pairs; leftPairs++) {
                int rightPairs = pairs - leftPairs - 1;

                for (const string& left : dp[leftPairs]) {
                    for (const string& right : dp[rightPairs])
                        dp[pairs].push_back("(" + left + ")" + right);
                }
            }
        }

        return dp[n];
    }
};