class Solution {
public:
    int kConcatenationMaxSum(
        vector<int>& arr,
        int k
    ) {
        const int MOD = 1000000007;

        long long total = 0;
        long long prefix = 0;
        long long bestPrefix = 0;

        for (int value : arr) {
            total += value;
            prefix += value;

            bestPrefix = max(
                bestPrefix,
                prefix
            );
        }

        long long suffix = 0;
        long long bestSuffix = 0;

        for (int i = static_cast<int>(arr.size()) - 1;
             i >= 0;
             i--) {
            suffix += arr[i];

            bestSuffix = max(
                bestSuffix,
                suffix
            );
        }

        long long current = 0;
        long long bestSingle = 0;

        for (int value : arr) {
            current = max(
                0LL,
                current + value
            );

            bestSingle = max(
                bestSingle,
                current
            );
        }

        long long answer =
            bestSingle;

        if (k >= 2) {
            answer = max(
                answer,
                bestPrefix +
                bestSuffix +
                max(
                    0LL,
                    total * (k - 2LL)
                )
            );
        }

        return static_cast<int>(
            answer % MOD
        );
    }
};
