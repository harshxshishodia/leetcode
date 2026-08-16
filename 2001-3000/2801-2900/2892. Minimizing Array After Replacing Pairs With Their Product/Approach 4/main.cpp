class Solution {
public:
    int minArrayLength(
        vector<int>& nums,
        int k
    ) {
        for (int value : nums) {
            if (value == 0) {
                return 1;
            }
        }

        int groups = 1;
        long long product =
            nums[0];

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            if (product <=
                k /
                nums[index]) {
                product *=
                    nums[index];
            } else {
                groups++;
                product =
                    nums[index];
            }
        }

        return groups;
    }
};
