class Solution {
    int solve(
        const vector<int>& nums,
        int left,
        int right,
        int score
    ) {
        if (right - left + 1 < 2) {
            return 0;
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

        return answer;
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
            solve(
                nums,
                2,
                n - 1,
                nums[0] + nums[1]
            )
        );

        answer = max(
            answer,
            1 +
            solve(
                nums,
                0,
                n - 3,
                nums[n - 2] + nums[n - 1]
            )
        );

        answer = max(
            answer,
            1 +
            solve(
                nums,
                1,
                n - 2,
                nums[0] + nums[n - 1]
            )
        );

        return answer;
    }
};
