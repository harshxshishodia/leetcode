class Solution {
    vector<int> memo;
    vector<bool> visited;

    int solve(
        const vector<int>& nums,
        int index
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n - 1) {
            return 0;
        }

        if (visited[index]) {
            return memo[index];
        }

        visited[index] =
            true;

        int answer = 0;

        for (int next = index + 1;
             next < n;
             next++) {
            answer = max(
                answer,
                (
                    next -
                    index
                ) *
                nums[next] +
                solve(
                    nums,
                    next
                )
            );
        }

        memo[index] =
            answer;

        return answer;
    }

public:
    int maxScore(vector<int>& nums) {
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
