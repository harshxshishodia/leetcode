class Solution {
    int solve(
        int left,
        int right,
        vector<vector<int>>& memo
    ) {
        if (left >= right) {
            return 0;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int answer = numeric_limits<int>::max();

        for (int guess = left; guess <= right; guess++) {
            int worstCase = guess + max(
                solve(left, guess - 1, memo),
                solve(guess + 1, right, memo)
            );

            answer = min(answer, worstCase);
        }

        memo[left][right] = answer;
        return memo[left][right];
    }

public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(
            n + 2,
            vector<int>(n + 2, -1)
        );

        return solve(1, n, memo);
    }
};
