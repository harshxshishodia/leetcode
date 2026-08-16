class Solution {
    bool possible(
        const vector<int>& nums,
        int k,
        int capability
    ) {
        int robbed = 0;

        for (int index = 0;
             index < static_cast<int>(nums.size());
             index++) {
            if (nums[index] <= capability) {
                robbed++;
                index++;

                if (robbed >= k) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    int minCapability(
        vector<int>& nums,
        int k
    ) {
        int left =
            *min_element(
                nums.begin(),
                nums.end()
            );

        int right =
            *max_element(
                nums.begin(),
                nums.end()
            );

        while (left < right) {
            int middle =
                left +
                (right - left) /
                2;

            if (possible(
                    nums,
                    k,
                    middle)) {
                right =
                    middle;
            } else {
                left =
                    middle + 1;
            }
        }

        return left;
    }
};
