class Solution {
public:
    long long maxEnergyBoost(
        vector<int>& energyDrinkA,
        vector<int>& energyDrinkB
    ) {
        int n =
            static_cast<int>(
                energyDrinkA.size()
            );

        vector<array<long long, 2>> dp(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index][0] = max(
                1LL *
                    energyDrinkA[index] +
                    dp[index + 1][0],
                dp[index + 1][1]
            );

            dp[index][1] = max(
                1LL *
                    energyDrinkB[index] +
                    dp[index + 1][1],
                dp[index + 1][0]
            );
        }

        return max(
            dp[0][0],
            dp[0][1]
        );
    }
};
