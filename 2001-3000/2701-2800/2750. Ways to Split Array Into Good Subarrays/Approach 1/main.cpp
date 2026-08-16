class Solution {
    bool good(
        const vector<int>& nums,
        int left,
        int right
    ) {
        int ones = 0;

        for (int index = left;
             index <= right;
             index++) {
            ones +=
                nums[index];
        }

        return ones == 1;
    }

public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(nums.size());

        if (n == 0) {
            return 0;
        }

        long long answer = 0;

        int boundaries =
            n - 1;

        for (int mask = 0;
             mask < (1 << boundaries);
             mask++) {
            int start = 0;
            bool valid = true;

            for (int index = 0;
                 index < boundaries;
                 index++) {
                if ((mask & (1 << index)) != 0) {
                    if (!good(
                            nums,
                            start,
                            index)) {
                        valid = false;
                        break;
                    }

                    start =
                        index + 1;
                }
            }

            if (valid &&
                good(
                    nums,
                    start,
                    n - 1)) {
                answer++;
            }
        }

        return static_cast<int>(
            answer %
            MOD
        );
    }
};
