class Solution {
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(
        const vector<int>& nums,
        int index,
        int sign
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return 0;
        }

        if (visited[index][sign]) {
            return memo[index][sign];
        }

        visited[index][sign] =
            true;

        long long answer;

        if (sign == 0) {
            answer =
                nums[index] +
                solve(
                    nums,
                    index + 1,
                    1
                );
        } else {
            long long continueCurrent =
                -1LL *
                nums[index] +
                solve(
                    nums,
                    index + 1,
                    0
                );

            long long split =
                nums[index] +
                solve(
                    nums,
                    index + 1,
                    1
                );

            answer = max(
                continueCurrent,
                split
            );
        }

        memo[index][sign] =
            answer;

        return answer;
    }

public:
    long long maximumTotalCost(vector<int>& nums) {
        memo.assign(
            nums.size(),
            {}
        );

        visited.assign(
            nums.size(),
            {}
        );

        return solve(
            nums,
            0,
            0
        );
    }
};
