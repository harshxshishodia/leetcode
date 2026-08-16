class Solution {
    static constexpr int MOD =
        1000000007;

    int limit;

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

        return static_cast<int>(
            answer %
            MOD
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

        return solve(
            zero,
            one,
            2,
            0
        );
    }
};
