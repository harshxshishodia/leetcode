class Solution {
    static constexpr int MOD = 1000000007;

    long long solve(
        int n,
        vector<long long>& memo
    ) {
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 0;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        memo[n] =
            1LL *
            (n - 1) *
            (solve(n - 1, memo) +
             solve(n - 2, memo)) %
            MOD;

        return memo[n];
    }

public:
    int findDerangement(int n) {
        vector<long long> memo(n + 1, -1);
        return static_cast<int>(solve(n, memo));
    }
};
