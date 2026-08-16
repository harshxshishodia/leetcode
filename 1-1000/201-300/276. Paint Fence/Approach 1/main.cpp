class Solution {
    long long search(
        int n,
        int k,
        int position,
        int previousColor,
        int consecutive
    ) {
        if (position == n) {
            return 1;
        }

        long long ways = 0;

        for (int color = 0; color < k; color++) {
            if (color == previousColor) {
                if (consecutive < 2) {
                    ways += search(
                        n,
                        k,
                        position + 1,
                        color,
                        consecutive + 1
                    );
                }
            } else {
                ways += search(
                    n,
                    k,
                    position + 1,
                    color,
                    1
                );
            }
        }

        return ways;
    }

public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }

        return static_cast<int>(search(n, k, 0, -1, 0));
    }
};
