class Solution {
    int solve(int n) {
        if (n == 1) {
            return 1;
        }

        int answer = 0;

        for (int first = 1; first < n; first++) {
            int remaining = n - first;

            answer = max(
                answer,
                first * max(
                    remaining,
                    solve(remaining)
                )
            );
        }

        return answer;
    }

public:
    int integerBreak(int n) {
        return solve(n);
    }
};
