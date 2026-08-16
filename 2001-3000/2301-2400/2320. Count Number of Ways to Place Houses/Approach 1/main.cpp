class Solution {
    static constexpr int MOD = 1000000007;

    long long solve(int plots, bool previousHouse) {
        if (plots == 0) {
            return 1;
        }

        long long answer =
            solve(
                plots - 1,
                false
            );

        if (!previousHouse) {
            answer +=
                solve(
                    plots - 1,
                    true
                );
        }

        return answer % MOD;
    }

public:
    int countHousePlacements(int n) {
        long long oneSide =
            solve(
                n,
                false
            );

        return static_cast<int>(
            oneSide *
            oneSide %
            MOD
        );
    }
};
