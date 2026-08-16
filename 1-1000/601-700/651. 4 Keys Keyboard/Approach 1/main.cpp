class Solution {
    int solve(int operations) {
        int answer = operations;

        for (int breakpoint = 1;
             breakpoint <= operations - 3;
             breakpoint++) {
            int pastes =
                operations - breakpoint - 2;

            answer = max(
                answer,
                solve(breakpoint) * (pastes + 1)
            );
        }

        return answer;
    }

public:
    int maxA(int n) {
        return solve(n);
    }
};
