class Solution {
    long long sumUpTo(int bound, int n) {
        if (bound <= 0) {
            return 0;
        }

        int highestBit = 0;

        while ((1LL << highestBit) <= bound) {
            highestBit++;
        }

        highestBit--;

        array<long long, 2> count = {0, 1};
        array<long long, 2> sum = {0, 0};

        for (int bit = highestBit; bit >= 0; bit--) {
            array<long long, 2> nextCount = {0, 0};
            array<long long, 2> nextSum = {0, 0};

            for (int tight = 0; tight <= 1; tight++) {
                if (count[tight] == 0) {
                    continue;
                }

                int boundBit = (bound >> bit) & 1;
                int limit = tight == 1 ? boundBit : 1;

                for (int digit = 0; digit <= limit; digit++) {
                    if (digit == 1 && ((n >> bit) & 1) == 1) {
                        continue;
                    }

                    int nextTight = tight == 1 && digit == boundBit ? 1 : 0;
                    nextCount[nextTight] += count[tight];
                    nextSum[nextTight] += sum[tight];
                    nextSum[nextTight] += count[tight] * digit * (1LL << bit);
                }
            }

            count = nextCount;
            sum = nextSum;
        }

        return sum[0] + sum[1];
    }

public:
    int sumOfCompatibleNumbers(int n, int k) {
        int left = max(1, n - k);
        int right = n + k;

        return static_cast<int>(
            sumUpTo(right, n) - sumUpTo(left - 1, n)
        );
    }
};
