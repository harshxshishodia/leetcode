class Solution {
    int solve(
        int operations,
        vector<int>& memo
    ) {
        if (memo[operations] != -1) {
            return memo[operations];
        }

        int answer = operations;

        for (int breakpoint = 1;
             breakpoint <= operations - 3;
             breakpoint++) {
            int pastes =
                operations - breakpoint - 2;

            answer = max(
                answer,
                solve(breakpoint, memo) * (pastes + 1)
            );
        }

        memo[operations] = answer;
        return memo[operations];
    }

public:
    int maxA(int n) {
        vector<int> memo(n + 1, -1);
        memo[0] = 0;

        return solve(n, memo);
    }
};
