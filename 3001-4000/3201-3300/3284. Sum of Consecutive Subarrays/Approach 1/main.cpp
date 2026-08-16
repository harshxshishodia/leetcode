class Solution {
    bool consecutive(
        const vector<int>& nums,
        int left,
        int right
    ) {
        if (left == right) {
            return true;
        }

        int difference =
            nums[left + 1] -
            nums[left];

        if (abs(difference) != 1) {
            return false;
        }

        for (int index = left + 2;
             index <= right;
             index++) {
            if (
                nums[index] -
                nums[index - 1] !=
                difference
            ) {
                return false;
            }
        }

        return true;
    }

public:
    int getSum(vector<int>& nums) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(nums.size());

        long long answer = 0;

        for (int left = 0;
             left < n;
             left++) {
            for (int right = left;
                 right < n;
                 right++) {
                if (!consecutive(
                        nums,
                        left,
                        right)) {
                    continue;
                }

                long long sum = 0;

                for (int index = left;
                     index <= right;
                     index++) {
                    sum +=
                        nums[index];
                }

                answer =
                    (
                        answer +
                        sum
                    ) %
                    MOD;
            }
        }

        return static_cast<int>(
            answer
        );
    }
};
