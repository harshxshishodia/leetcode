class Solution {
    double solve(
        int a,
        int b
    ) {
        if (a <= 0 &&
            b <= 0) {
            return 0.5;
        }

        if (a <= 0) {
            return 1.0;
        }

        if (b <= 0) {
            return 0.0;
        }

        return 0.25 * (
            solve(
                a - 100,
                b
            ) +
            solve(
                a - 75,
                b - 25
            ) +
            solve(
                a - 50,
                b - 50
            ) +
            solve(
                a - 25,
                b - 75
            )
        );
    }

public:
    double soupServings(int n) {
        return solve(
            n,
            n
        );
    }
};
