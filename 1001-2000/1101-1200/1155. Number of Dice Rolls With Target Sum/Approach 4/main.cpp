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

            for (int sum = 1; sum <= target; sum++) {
                long long ways = 0;

                for (int face = 1;
                     face <= k &&
                     face <= sum;
                     face++) {
                    ways +=
                        previous[sum - face];
                }

                current[sum] =
                    static_cast<int>(
                        ways % MOD
                    );
            }

            previous = current;
        }

        return previous[target];
    }
};
