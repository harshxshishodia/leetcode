class Solution {
    static constexpr int MOD =
        1000000007;

    int limit;

    vector<
        vector<
            array<vector<int>, 2>
        >
    > memo;

    int solve(
        int zero,
        int one,
        int last,
        int run
    ) {
        if (zero == 0 &&
            one == 0) {
            return 1;
        }

        if (
            last != 2 &&
            memo[zero][one][last][run] != -1
        ) {
            return
                memo[zero][one][last][run];
        }

        long long answer = 0;

        if (zero > 0 &&
            (
                last != 0 ||
                run < limit
            )) {
            answer +=
                solve(
                    zero - 1,
                    one,
                    0,
                    last == 0
                        ? run + 1
                        : 1
                );
        }

        if (one > 0 &&
            (
                last != 1 ||
                run < limit
            )) {
            answer +=
                solve(
                    zero,
                    one - 1,
                    1,
                    last == 1
                        ? run + 1
                        : 1
                );
        }

        answer %=
            MOD;

        if (last != 2) {
            memo[zero][one][last][run] =
                static_cast<int>(
                    answer
                );
        }

        return static_cast<int>(
            answer
        );
    }

public:
    int numberOfStableArrays(
        int zero,
        int one,
        int inputLimit
    ) {
        limit =
            inputLimit;

        memo.resize(
            zero + 1
        );

        for (int z = 0;
             z <= zero;
             z++) {
            memo[z].resize(
                one + 1
            );

            for (int o = 0;
                 o <= one;
                 o++) {
                for (int bit = 0;
                     bit <= 1;
                     bit++) {
                    memo[z][o][bit].assign(
                        limit + 1,
                        -1
                    );
                }
            }
        }

        return solve(
            zero,
            one,
            2,
            0
        );
    }
};
