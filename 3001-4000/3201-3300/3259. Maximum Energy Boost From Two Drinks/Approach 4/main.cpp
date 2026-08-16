class Solution {
public:
    long long maxEnergyBoost(
        vector<int>& energyDrinkA,
        vector<int>& energyDrinkB
    ) {
        long long nextA = 0;
        long long nextB = 0;

        for (int index =
                 static_cast<int>(
                     energyDrinkA.size()
                 ) -
                 1;
             index >= 0;
             index--) {
            long long currentA = max(
                1LL *
                    energyDrinkA[index] +
                    nextA,
                nextB
            );

            long long currentB = max(
                1LL *
                    energyDrinkB[index] +
                    nextB,
                nextA
            );

            nextA =
                currentA;

            nextB =
                currentB;
        }

        return max(
            nextA,
            nextB
        );
    }
};
