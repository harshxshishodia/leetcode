class Solution {
    int n;
    vector<int> memo;

    int solve(int mask) {
        int position =
            __builtin_popcount(
                static_cast<unsigned int>(mask)
            ) +
            1;

        if (position > n) {
            return 1;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        int answer = 0;

        for (int value = 1;
             value <= n;
             value++) {
            int bit =
                1 <<
                (value - 1);

            if ((mask & bit) != 0) {
                continue;
            }

            if (
                value %
                    position !=
                    0 &&
                position %
                    value !=
                    0
            ) {
                continue;
            }

            answer +=
                solve(
                    mask |
                    bit
                );
        }

        memo[mask] =
            answer;

        return answer;
    }

public:
    int selfDivisiblePermutationCount(int inputN) {
        n =
            inputN;

        memo.assign(
            1 << n,
            -1
        );

        return solve(0);
    }
};
