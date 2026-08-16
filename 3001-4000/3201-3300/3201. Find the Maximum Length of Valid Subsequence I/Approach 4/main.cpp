class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        int alternating = 1;

        for (int value : nums) {
            if (value & 1) {
                odd++;
            } else {
                even++;
            }
        }

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            if (
                (nums[index] & 1) !=
                (nums[index - 1] & 1)
            ) {
                alternating++;
            }
        }

        return max({
            even,
            odd,
            alternating
        });
    }
};
