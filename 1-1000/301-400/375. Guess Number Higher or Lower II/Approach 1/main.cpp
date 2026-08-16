class Solution {
    int solve(int left, int right) {
        if (left >= right) {
            return 0;
        }

        int answer = numeric_limits<int>::max();

        for (int guess = left; guess <= right; guess++) {
            int worstCase = guess + max(
                solve(left, guess - 1),
                solve(guess + 1, right)
            );

            answer = min(answer, worstCase);
        }

        return answer;
    }

public:
    int getMoneyAmount(int n) {
        return solve(1, n);
    }
};
