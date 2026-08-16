class Solution {
    int solve(int n, vector<int>& memo) {
        if (n == 1) {
            return 1;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        int answer = 0;

        for (int first = 1; first < n; first++) {
            int remaining = n - first;

            answer = max(
                answer,
                first * max(
                    remaining,
                    solve(remaining, memo)
                )
            );
        }

        memo[n] = answer;
        return memo[n];
    }

public:
    int integerBreak(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};
