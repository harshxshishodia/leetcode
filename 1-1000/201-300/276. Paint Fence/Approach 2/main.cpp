class Solution {
    long long solve(int posts, int colors) {
        if (posts == 1) {
            return colors;
        }

        if (posts == 2) {
            return 1LL * colors * colors;
        }

        return 1LL * (colors - 1) *
               (solve(posts - 1, colors) +
                solve(posts - 2, colors));
    }

public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }

        return static_cast<int>(solve(n, k));
    }
};
