class Solution {
    bool possible(
        const vector<int>& nums,
        long long limit
    ) {
        long long carry = 0;

        for (int index =
                 static_cast<int>(nums.size()) - 1;
             index >= 1;
             index--) {
            long long value =
                nums[index] +
                carry;

            carry = max(
                0LL,
                value - limit
            );
        }

        return
            nums[0] +
            carry <=
            limit;
    }

public:
    int minimizeArrayValue(vector<int>& nums) {
        long long left = 0;
        long long right =
            *max_element(
                nums.begin(),
                nums.end()
            );

        while (left < right) {
            long long middle =
                left +
                (right - left) /
                2;

            if (possible(
                    nums,
                    middle)) {
                right =
                    middle;
            } else {
                left =
                    middle + 1;
            }
        }

        return static_cast<int>(
            left
        );
    }
};
