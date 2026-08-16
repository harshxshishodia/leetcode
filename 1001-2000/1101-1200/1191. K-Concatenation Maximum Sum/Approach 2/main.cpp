class Solution {
public:
    int kConcatenationMaxSum(
        vector<int>& arr,
        int k
    ) {
        const int MOD = 1000000007;

        long long total =
            accumulate(
                arr.begin(),
                arr.end(),
                0LL
            );

        long long best = 0;
        long long current = 0;

        int copies =
            min(
                k,
                2
            );

        for (int copy = 0; copy < copies; copy++) {
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

        if (k > 2 &&
            total > 0) {
            best +=
                total *
                (k - 2LL);
        }

        return static_cast<int>(
            best % MOD
        );
    }
};
