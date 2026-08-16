class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int NEG =
            -1000000000;

        array<int, 3> best = {
            0,
            NEG,
            NEG
        };

        for (int value : nums) {
            array<int, 3> previous =
                best;

            for (int remainder = 0;
                 remainder < 3;
                 remainder++) {
                if (previous[remainder] == NEG) {
                    continue;
                }

                int nextRemainder =
                    (
                        remainder +
                        value
                    ) %
                    3;

                best[nextRemainder] = max(
                    best[nextRemainder],
                    previous[remainder] +
                    value
                );
            }
        }

        return best[0];
    }
};
