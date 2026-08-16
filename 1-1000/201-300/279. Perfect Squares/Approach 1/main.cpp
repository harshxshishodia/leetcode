class Solution {
    int solve(int n) {
        if (n == 0) {
            return 0;
        }

        int answer = n;

        for (int value = 1; value * value <= n; value++) {
            answer = min(
                answer,
                1 + solve(n - value * value)
            );
        }

        return answer;
    }

public:
    int numSquares(int n) {
        return solve(n);
    }
};
