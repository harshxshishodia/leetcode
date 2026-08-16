class Solution {
    int solve(long long n) {
        if (n == 1) {
            return 0;
        }

        if (n % 2 == 0) {
            return 1 + solve(n / 2);
        }

        return 1 + min(
            solve(n - 1),
            solve(n + 1)
        );
    }

public:
    int integerReplacement(int n) {
        return solve(n);
    }
};
