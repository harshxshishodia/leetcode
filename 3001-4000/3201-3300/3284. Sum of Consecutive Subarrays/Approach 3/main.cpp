class Solution {
public:
    int getSum(vector<int>& nums) {
        const long long MOD =
            1000000007;

        int n =
            static_cast<int>(nums.size());

        long long answer = 0;

        for (int value : nums) {
            answer +=
                value;

            answer %=
                MOD;
        }

        int edge = 0;

        while (edge < n - 1) {
            int difference =
                nums[edge + 1] -
                nums[edge];

            if (abs(difference) != 1) {
                edge++;
                continue;
            }

            int left =
                edge;

            while (
                edge + 1 <
                    n -
                    1 &&
                nums[edge + 2] -
                    nums[edge + 1] ==
                    difference
            ) {
                edge++;
            }

            int right =
                edge +
                1;

            for (int index = left;
                 index <= right;
                 index++) {
                long long count =
                    1LL *
                    (
                        index -
                        left +
                        1
                    ) *
                    (
                        right -
                        index +
                        1
                    ) -
                    1;

                answer =
                    (
                        answer +
                        count *
                        nums[index]
                    ) %
                    MOD;
            }

            edge =
                right;
        }

        return static_cast<int>(
            answer
        );
    }
};
