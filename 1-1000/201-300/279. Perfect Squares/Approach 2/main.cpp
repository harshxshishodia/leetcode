class Solution {
    int solve(int n, vector<int>& memo) {
        if (n == 0) {
            return 0;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        int answer = n;

        for (int value = 1; value * value <= n; value++) {
            answer = min(
                answer,
                1 + solve(n - value * value, memo)
            );
        }

        memo[n] = answer;
        return memo[n];
    }

public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};
