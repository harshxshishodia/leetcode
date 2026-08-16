class Solution {
    static constexpr int MOD = 1000000007;
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(
        int plots,
        int previousHouse
    ) {
        if (plots == 0) {
            return 1;
        }

        if (visited[plots][previousHouse]) {
            return memo[plots][previousHouse];
        }

        visited[plots][previousHouse] = true;

        long long answer =
            solve(
                plots - 1,
                0
            );

        if (!previousHouse) {
            answer +=
                solve(
                    plots - 1,
                    1
                );
        }

        memo[plots][previousHouse] =
            answer %
            MOD;

        return memo[plots][previousHouse];
    }

public:
    int countHousePlacements(int n) {
        memo.assign(
            n + 1,
            {}
        );

        visited.assign(
            n + 1,
            {}
        );

        long long oneSide =
            solve(
                n,
                0
            );

        return static_cast<int>(
            oneSide *
            oneSide %
            MOD
        );
    }
};
