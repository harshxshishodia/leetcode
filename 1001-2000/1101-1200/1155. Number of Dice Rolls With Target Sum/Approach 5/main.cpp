class Solution {
public:
    int numRollsToTarget(
        int n,
        int k,
        int target
    ) {
        const int MOD = 1000000007;

        vector<int> previous(
            target + 1
        );

        previous[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            vector<int> current(
                target + 1
            );

            long long window = 0;

            for (int sum = 1; sum <= target; sum++) {
                window +=
                    previous[sum - 1];

                if (sum - k - 1 >= 0) {
                    window -=
                        previous[sum - k - 1];
                }

                window %= MOD;

                if (window < 0) {
                    window += MOD;
                }

                current[sum] =
                    static_cast<int>(window);
            }

            previous = current;
        }

        return previous[target];
    }
};
