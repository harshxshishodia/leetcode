class Solution {
    vector<vector<int>> memo;

    int solve(
        const vector<int>& nums,
        int index,
        int segments
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n) {
            return segments == 0
                ? 0
                : 1000000000;
        }

        if (segments == 0) {
            return 1000000000;
        }

        if (memo[index][segments] != -1) {
            return memo[index][segments];
        }

        int maximum = 0;
        int sum = 0;
        int answer =
            1000000000;

        for (int end = index;
             end < n;
             end++) {
            maximum = max(
                maximum,
                nums[end]
            );

            sum +=
                nums[end];

            int waste =
                maximum *
                (end - index + 1) -
                sum;

            answer = min(
                answer,
                waste +
                solve(
                    nums,
                    end + 1,
                    segments - 1
                )
            );
        }

        memo[index][segments] =
            answer;

        return memo[index][segments];
    }

public:
    int minSpaceWastedKResizing(
        vector<int>& nums,
        int k
    ) {
        int segments = min(
            static_cast<int>(nums.size()),
            k + 1
        );

        memo.assign(
            nums.size(),
            vector<int>(
                segments + 1,
                -1
            )
        );

        return solve(
            nums,
            0,
            segments
        );
    }
};
