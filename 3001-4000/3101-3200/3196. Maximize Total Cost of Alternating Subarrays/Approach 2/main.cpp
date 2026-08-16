class Solution {
    vector<long long> memo;
    vector<bool> visited;

    long long solve(
        const vector<int>& nums,
        int index
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return 0;
        }

        if (visited[index]) {
            return memo[index];
        }

        visited[index] =
            true;

        long long answer =
            numeric_limits<long long>::min() /
            4;

        long long cost = 0;
        int sign = 1;

        for (int end = index;
             end < static_cast<int>(nums.size());
             end++) {
            cost +=
                1LL *
                sign *
                nums[end];

            sign *=
                -1;

            answer = max(
                answer,
                cost +
                solve(
                    nums,
                    end + 1
                )
            );
        }

        memo[index] =
            answer;

        return answer;
    }

public:
    long long maximumTotalCost(vector<int>& nums) {
        memo.assign(
            nums.size(),
            0
        );

        visited.assign(
            nums.size(),
            false
        );

        return solve(
            nums,
            0
        );
    }
};
