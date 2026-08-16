class Solution {
    long long solve(int posts, int colors, vector<long long>& memo) {
        if (posts == 1) {
            return colors;
        }

        if (posts == 2) {
            return 1LL * colors * colors;
        }

        if (memo[posts] != -1) {
            return memo[posts];
        }

        memo[posts] = 1LL * (colors - 1) *
                      (solve(posts - 1, colors, memo) +
                       solve(posts - 2, colors, memo));

        return memo[posts];
    }

public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }

        vector<long long> memo(n + 1, -1);
        return static_cast<int>(solve(n, k, memo));
    }
};
