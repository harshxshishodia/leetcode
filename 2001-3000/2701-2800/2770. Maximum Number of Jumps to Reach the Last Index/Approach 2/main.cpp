class Solution {
    vector<int> memo;

    int solve(
        const vector<int>& nums,
        int target,
        int index
    ) {
        if (index ==
            static_cast<int>(nums.size()) - 1) {
            return 0;
        }

        if (memo[index] != -2) {
            return memo[index];
        }

        const int NEG =
            -1000000000;

        int answer =
            NEG;

        for (int next = index + 1;
             next < static_cast<int>(nums.size());
             next++) {
            if (abs(
                    nums[next] -
                    nums[index]
                ) > target) {
                continue;
            }

            int result =
                solve(
                    nums,
                    target,
                    next
                );

            if (result != NEG) {
                answer = max(
                    answer,
                    1 + result
                );
            }
        }

        memo[index] =
            answer;

        return answer;
    }

public:
    int maximumJumps(
        vector<int>& nums,
        int target
    ) {
        memo.assign(
            nums.size(),
            -2
        );

        int answer =
            solve(
                nums,
                target,
                0
            );

        return answer < 0
            ? -1
            : answer;
    }
};
