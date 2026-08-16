class Solution {
public:
    int maxFrequency(
        vector<int>& nums,
        int k
    ) {
        int base = 0;

        for (int value :
             nums) {
            base +=
                value ==
                k;
        }

        int bestGain = 0;

        for (int candidate = 1;
             candidate <= 50;
             candidate++) {
            if (candidate == k) {
                continue;
            }

            int current = 0;

            for (int value :
                 nums) {
                int contribution = 0;

                if (value == candidate) {
                    contribution =
                        1;
                } else if (value == k) {
                    contribution =
                        -1;
                }

                current = max(
                    0,
                    current +
                    contribution
                );

                bestGain = max(
                    bestGain,
                    current
                );
            }
        }

        return
            base +
            bestGain;
    }
};
