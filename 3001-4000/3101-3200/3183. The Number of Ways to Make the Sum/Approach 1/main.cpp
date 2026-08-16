class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> coins = {
        1,
        2,
        4,
        6
    };

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

        return static_cast<int>(
            answer %
            MOD
        );
    }

public:
    int numberOfWays(int n) {
        return solve(
            0,
            n,
            0
        );
    }
};
