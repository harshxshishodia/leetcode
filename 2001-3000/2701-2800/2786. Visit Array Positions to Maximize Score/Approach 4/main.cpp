class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        const long long NEG =
            numeric_limits<long long>::min() / 4;

        long long even = NEG;
        long long odd = NEG;

        if (nums[0] & 1) {
            odd = nums[0];
        } else {
            even = nums[0];
        }

        for (int index = 1; index < static_cast<int>(nums.size()); index++) {
            long long oldEven = even;
            long long oldOdd = odd;

            if (nums[index] & 1) {
                odd = max(
                    oldOdd,
                    max(
                        oldOdd + nums[index],
                        oldEven + nums[index] - x
                    )
                );
            } else {
                even = max(
                    oldEven,
                    max(
                        oldEven + nums[index],
                        oldOdd + nums[index] - x
                    )
                );
            }
        }

        return max(even, odd);
    }
};
