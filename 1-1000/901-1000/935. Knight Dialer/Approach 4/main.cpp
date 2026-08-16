class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1000000007;

        static const vector<vector<int>> next = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        vector<long long> current(
            10,
            1
        );

        for (int length = 2; length <= n; length++) {
            vector<long long> nextCount(10);

            for (int digit = 0; digit <= 9; digit++) {
                for (int nextDigit : next[digit]) {
                    nextCount[nextDigit] +=
                        current[digit];

                    nextCount[nextDigit] %= MOD;
                }
            }

            current = nextCount;
        }

        long long answer = 0;

        for (long long count : current) {
            answer += count;
            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
