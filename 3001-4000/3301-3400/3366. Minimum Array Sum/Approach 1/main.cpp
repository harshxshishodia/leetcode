class Solution {
    int solve(
        const vector<int>& nums,
        int k,
        int index,
        int op1,
        int op2
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return 0;
        }

        int value =
            nums[index];

        int answer =
            value +
            solve(
                nums,
                k,
                index + 1,
                op1,
                op2
            );

        if (op1 > 0) {
            int after =
                (value + 1) /
                2;

            answer = min(
                answer,
                after +
                solve(
                    nums,
                    k,
                    index + 1,
                    op1 - 1,
                    op2
                )
            );
        }

        if (op2 > 0 &&
            value >= k) {
            int after =
                value -
                k;

            answer = min(
                answer,
                after +
                solve(
                    nums,
                    k,
                    index + 1,
                    op1,
                    op2 - 1
                )
            );
        }

        if (op1 > 0 &&
            op2 > 0) {
            int half =
                (value + 1) /
                2;

            if (half >= k) {
                answer = min(
                    answer,
                    half -
                    k +
                    solve(
                        nums,
                        k,
                        index + 1,
                        op1 - 1,
                        op2 - 1
                    )
                );
            }

            if (value >= k) {
                int after =
                    (
                        value -
                        k +
                        1
                    ) /
                    2;

                answer = min(
                    answer,
                    after +
                    solve(
                        nums,
                        k,
                        index + 1,
                        op1 - 1,
                        op2 - 1
                    )
                );
            }
        }

        return answer;
    }

public:
    int minArraySum(
        vector<int>& nums,
        int k,
        int op1,
        int op2
    ) {
        return solve(
            nums,
            k,
            0,
            op1,
            op2
        );
    }
};
