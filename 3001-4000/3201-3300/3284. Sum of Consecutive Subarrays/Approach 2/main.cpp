class Solution {
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
            long long sum =
                nums[left];

            answer =
                (
                    answer +
                    sum
                ) %
                MOD;

            int direction = 0;

            for (int right = left + 1;
                 right < n;
                 right++) {
                int difference =
                    nums[right] -
                    nums[right - 1];

                if (abs(difference) != 1) {
                    break;
                }

                if (direction == 0) {
                    direction =
                        difference;
                } else if (direction !=
                           difference) {
                    break;
                }

                sum +=
                    nums[right];

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
