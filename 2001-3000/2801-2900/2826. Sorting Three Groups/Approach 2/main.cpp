class Solution {
    vector<array<int, 4>> memo;
    vector<array<bool, 4>> visited;

    int solve(const vector<int>& nums, int index, int previous) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        if (visited[index][previous]) {
            return memo[index][previous];
        }

        visited[index][previous] = true;

        int answer =
            numeric_limits<int>::max();

        for (int value = previous; value <= 3; value++) {
            answer = min(
                answer,
                (nums[index] != value) +
                solve(
                    nums,
                    index + 1,
                    value
                )
            );
        }

        memo[index][previous] =
            answer;

        return answer;
    }

public:
    int minimumOperations(vector<int>& nums) {
        memo.assign(nums.size(), {});
        visited.assign(nums.size(), {});

        return solve(
            nums,
            0,
            1
        );
    }
};
