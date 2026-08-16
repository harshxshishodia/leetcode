class Solution {
    double solve(int n) {
        if (n == 1) {
            return 1.0;
        }

        double answer =
            1.0 / n;

        for (int seat = 2;
             seat < n;
             seat++) {
            answer +=
                solve(
                    n - seat + 1
                ) /
                n;
        }

        return answer;
    }

public:
    double nthPersonGetsNthSeat(int n) {
        return solve(n);
    }
};
