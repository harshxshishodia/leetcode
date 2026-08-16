class Solution {
public:
    int kConcatenationMaxSum(
        vector<int>& arr,
        int k
    ) {
        const long long MOD = 1000000007;

        long long total = 0;
        long long bestPrefix = 0;
        long long prefix = 0;
        long long bestSuffix = 0;
        long long suffix = 0;
        long long bestSingle = 0;
        long long current = 0;

        for (int value : arr) {
            total += value;
            prefix += value;

            bestPrefix = max(
                bestPrefix,
                prefix
            );

            current = max(
                0LL,
                current + value
            );

            bestSingle = max(
                bestSingle,
                current
            );
        }

        for (int i = static_cast<int>(arr.size()) - 1;
             i >= 0;
             i--) {
            suffix += arr[i];

            bestSuffix = max(
                bestSuffix,
                suffix
            );
        }

        long long answer =
            bestSingle;

        if (k > 1) {
            long long middle =
                total > 0
                    ? total * (k - 2LL)
                    : 0LL;

            answer = max(
                answer,
                bestSuffix +
                bestPrefix +
                middle
            );
        }

        return static_cast<int>(
            answer % MOD
        );
    }
};
