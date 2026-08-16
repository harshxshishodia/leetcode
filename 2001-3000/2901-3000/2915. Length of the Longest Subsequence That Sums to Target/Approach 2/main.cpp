class Solution {
    static constexpr int NEG =
        -1000000000;

    vector<vector<int>> memo;
    vector<vector<bool>> visited;

    int solve(
        const vector<int>& nums,
        int index,
        int remaining
    ) {
        if (remaining == 0) {
            return 0;
        }

        if (index ==
            static_cast<int>(nums.size())) {
            return NEG;
        }

        if (visited[index][remaining]) {
            return memo[index][remaining];
        }

        visited[index][remaining] =
            true;

        int skip =
            solve(
                nums,
                index + 1,
                remaining
            );

        int take =
            NEG;

        if (nums[index] <= remaining) {
            int next =
                solve(
                    nums,
                    index + 1,
                    remaining -
                    nums[index]
                );

            if (next != NEG) {
                take =
                    1 +
                    next;
            }
        }

        memo[index][remaining] = max(
            skip,
            take
        );

        return memo[index][remaining];
    }

public:
    int lengthOfLongestSubsequence(
        vector<int>& nums,
        int target
    ) {
        memo.assign(
            nums.size(),
            vector<int>(
                target + 1
            )
        );

        visited.assign(
            nums.size(),
            vector<bool>(
                target + 1
            )
        );

        int answer =
            solve(
                nums,
                0,
                target
            );

        return answer < 0
            ? -1
            : answer;
    }
};
