class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> coins = {
        1,
        2,
        4,
        6
    };

    vector<vector<array<int, 3>>> memo;
    vector<vector<array<bool, 3>>> visited;

    int solve(
        int index,
        int remaining,
        int usedFour
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (
            index ==
                static_cast<int>(
                    coins.size()
                ) ||
            remaining < 0
        ) {
            return 0;
        }

        if (
            visited[index][remaining][usedFour]
        ) {
            return
                memo[index][remaining][usedFour];
        }

        visited[index][remaining][usedFour] =
            true;

        long long answer =
            solve(
                index + 1,
                remaining,
                usedFour
            );

        if (
            coins[index] != 4 ||
            usedFour < 2
        ) {
            answer +=
                solve(
                    index,
                    remaining -
                    coins[index],
                    usedFour +
                    (
                        coins[index] ==
                        4
                    )
                );
        }

        memo[index][remaining][usedFour] =
            static_cast<int>(
                answer %
                MOD
            );

        return
            memo[index][remaining][usedFour];
    }

public:
    int numberOfWays(int n) {
        memo.assign(
            coins.size(),
            vector<array<int, 3>>(
                n + 1
            )
        );

        visited.assign(
            coins.size(),
            vector<array<bool, 3>>(
                n + 1
            )
        );

        return solve(
            0,
            n,
            0
        );
    }
};
