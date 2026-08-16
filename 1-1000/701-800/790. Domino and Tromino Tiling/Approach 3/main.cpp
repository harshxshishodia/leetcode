class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1000000007;

        vector<long long> full(
            n + 1
        );

        vector<long long> gap(
            n + 1
        );

        full[0] = 1;

        if (n >= 1) {
            full[1] = 1;
        }

        for (int width = 2; width <= n; width++) {
            gap[width] = (
                gap[width - 1] +
                full[width - 2]
            ) % MOD;

            full[width] = (
                full[width - 1] +
                full[width - 2] +
                2 * gap[width - 1]
            ) % MOD;
        }

        return static_cast<int>(
            full[n]
        );
    }
};
