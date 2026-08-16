class Solution {
    static constexpr int MOD = 1000000007;

    long long solve(int n) {
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 0;
        }

        return
            1LL *
            (n - 1) *
            (solve(n - 1) + solve(n - 2)) %
            MOD;
    }

public:
    int findDerangement(int n) {
        return static_cast<int>(solve(n));
    }
};
