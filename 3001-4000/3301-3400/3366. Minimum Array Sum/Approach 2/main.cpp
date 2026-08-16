class Solution {
    vector<
        vector<
            vector<int>
        >
    > memo;

    vector<
        vector<
            vector<bool>
        >
    > visited;

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

        if (visited[index][op1][op2]) {
            return memo[index][op1][op2];
        }

        visited[index][op1][op2] =
            true;

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
            answer = min(
                answer,
                value -
                k +
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

        memo[index][op1][op2] =
            answer;

        return answer;
    }

public:
    int minArraySum(
        vector<int>& nums,
        int k,
        int op1,
        int op2
    ) {
        memo.assign(
            nums.size(),
            vector<vector<int>>(
                op1 + 1,
                vector<int>(
                    op2 + 1
                )
            )
        );

        visited.assign(
            nums.size(),
            vector<vector<bool>>(
                op1 + 1,
                vector<bool>(
                    op2 + 1
                )
            )
        );

        return solve(
            nums,
            k,
            0,
            op1,
            op2
        );
    }
};
