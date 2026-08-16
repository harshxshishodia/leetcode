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

            for (int left = 0;
                 left < static_cast<int>(nums.size());
                 left++) {
                int gain = 0;

                for (int right = left;
                     right < static_cast<int>(nums.size());
                     right++) {
                    if (nums[right] ==
                        candidate) {
                        gain++;
                    }

                    if (nums[right] ==
                        k) {
                        gain--;
                    }

                    bestGain = max(
                        bestGain,
                        gain
                    );
                }
            }
        }

        return
            base +
            bestGain;
    }
};
