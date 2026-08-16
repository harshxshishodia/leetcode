class Solution {
public:
    int getSum(vector<int>& nums) {
        const long long MOD =
            1000000007;

        long long answer =
            nums[0] %
            MOD;

        long long increasingSum =
            nums[0];

        long long decreasingSum =
            nums[0];

        long long increasingCount = 1;
        long long decreasingCount = 1;

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            int difference =
                nums[index] -
                nums[index - 1];

            if (difference == 1) {
                increasingCount++;

                increasingSum =
                    (
                        increasingSum +
                        increasingCount *
                        nums[index]
                    ) %
                    MOD;

                decreasingCount = 1;
                decreasingSum =
                    nums[index];

                answer =
                    (
                        answer +
                        increasingSum
                    ) %
                    MOD;
            } else if (difference == -1) {
                decreasingCount++;

                decreasingSum =
                    (
                        decreasingSum +
                        decreasingCount *
                        nums[index]
                    ) %
                    MOD;

                increasingCount = 1;
                increasingSum =
                    nums[index];

                answer =
                    (
                        answer +
                        decreasingSum
                    ) %
                    MOD;
            } else {
                increasingCount = 1;
                decreasingCount = 1;

                increasingSum =
                    nums[index];

                decreasingSum =
                    nums[index];

                answer =
                    (
                        answer +
                        nums[index]
                    ) %
                    MOD;
            }
        }

        return static_cast<int>(
            answer
        );
    }
};
