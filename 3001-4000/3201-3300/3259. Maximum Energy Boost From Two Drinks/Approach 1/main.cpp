class Solution {
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

        return max(
            consume,
            switchDrink
        );
    }

public:
    long long maxEnergyBoost(
        vector<int>& energyDrinkA,
        vector<int>& energyDrinkB
    ) {
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
