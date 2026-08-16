class Solution {
    vector<vector<int>> memo;

    int solve(
        const vector<int>& nums,
        int left,
        int right,
        int score
    ) {
        if (right - left + 1 < 2) {
            return 0;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int answer = 0;

        if (nums[left] + nums[left + 1] == score) {
            answer = max(
                answer,
                1 +
                solve(
                    nums,
                    left + 2,
                    right,
                    score
                )
            );
        }

        if (nums[right - 1] + nums[right] == score) {
            answer = max(
                answer,
                1 +
                solve(
                    nums,
                    left,
                    right - 2,
                    score
                )
            );
        }

        if (nums[left] + nums[right] == score) {
            answer = max(
                answer,
                1 +
                solve(
                    nums,
                    left + 1,
                    right - 1,
                    score
                )
            );
        }

        memo[left][right] =
            answer;

        return answer;
    }

    int run(
        const vector<int>& nums,
        int left,
        int right,
        int score
    ) {
        int n =
            static_cast<int>(nums.size());

        memo.assign(
            n,
            vector<int>(
                n,
                -1
            )
        );

        return solve(
            nums,
            left,
            right,
            score
        );
    }

public:
    int maxOperations(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        if (n < 2) {
            return 0;
        }

        int answer = 0;

        answer = max(
            answer,
            1 +
            run(
                nums,
                2,
                n - 1,
                nums[0] + nums[1]
            )
        );

        answer = max(
            answer,
            1 +
            run(
                nums,
                0,
                n - 3,
                nums[n - 2] + nums[n - 1]
            )
        );

        answer = max(
            answer,
            1 +
            run(
                nums,
                1,
                n - 2,
                nums[0] + nums[n - 1]
            )
        );

        return answer;
    }
};
