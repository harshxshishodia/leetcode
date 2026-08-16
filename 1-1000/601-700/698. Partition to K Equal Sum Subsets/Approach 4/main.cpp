class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        if (total % k != 0) {
            return false;
        }

        int target = total / k;

        if (*max_element(
                nums.begin(),
                nums.end()) > target) {
            return false;
        }

        int n = static_cast<int>(nums.size());
        int states = 1 << n;

        vector<int> remainder(
            states,
            -1
        );

        remainder[0] = 0;

        for (int mask = 0; mask < states; mask++) {
            if (remainder[mask] == -1) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                int bit = 1 << i;

                if ((mask & bit) != 0) {
                    continue;
                }

                int next =
                    remainder[mask] + nums[i];

                if (next > target) {
                    continue;
                }

                remainder[mask | bit] =
                    next % target;
            }
        }

        return remainder[states - 1] == 0;
    }
};
