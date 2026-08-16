class Solution {
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(
        const vector<int>& a,
        const vector<int>& b,
        int index,
        int drink
    ) {
        if (index ==
            static_cast<int>(a.size())) {
            return 0;
        }

        if (visited[index][drink]) {
            return memo[index][drink];
        }

        visited[index][drink] =
            true;

        long long consume =
            (
                drink == 0
                    ? a[index]
                    : b[index]
            ) +
            solve(
                a,
                b,
                index + 1,
                drink
            );

        long long switchDrink =
            solve(
                a,
                b,
                index + 1,
                1 -
                drink
            );

        memo[index][drink] = max(
            consume,
            switchDrink
        );

        return memo[index][drink];
    }

public:
    long long maxEnergyBoost(
        vector<int>& energyDrinkA,
        vector<int>& energyDrinkB
    ) {
        memo.assign(
            energyDrinkA.size(),
            {}
        );

        visited.assign(
            energyDrinkA.size(),
            {}
        );

        return max(
            solve(
                energyDrinkA,
                energyDrinkB,
                0,
                0
            ),
            solve(
                energyDrinkA,
                energyDrinkB,
                0,
                1
            )
        );
    }
};
