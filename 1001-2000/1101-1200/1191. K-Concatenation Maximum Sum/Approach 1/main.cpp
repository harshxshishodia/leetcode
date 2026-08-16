class Solution {
public:
    int kConcatenationMaxSum(
        vector<int>& arr,
        int k
    ) {
        const int MOD = 1000000007;

        long long best = 0;
        long long current = 0;

        for (int copy = 0; copy < k; copy++) {
            for (int value : arr) {
                current = max(
                    0LL,
                    current + value
                );

                best = max(
                    best,
                    current
                );
            }
        }

        return static_cast<int>(
            best % MOD
        );
    }
};
