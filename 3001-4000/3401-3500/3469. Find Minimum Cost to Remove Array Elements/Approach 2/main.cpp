class Solution {
    vector<vector<int>> memo;
    vector<vector<bool>> visited;
    vector<int> nums;

    int solve(
        int nextIndex,
        int carried
    ) {
        int n =
            static_cast<int>(nums.size());

        if (nextIndex >= n) {
            return nums[carried];
        }

        if (nextIndex == n - 1) {
            return max(
                nums[carried],
                nums[nextIndex]
            );
        }

        if (visited[nextIndex][carried]) {
            return memo[nextIndex][carried];
        }

        visited[nextIndex][carried] =
            true;

        int first =
            carried;

        int second =
            nextIndex;

        int third =
            nextIndex + 1;

        int answer =
            numeric_limits<int>::max();

        answer = min(
            answer,
            max(
                nums[second],
                nums[third]
            ) +
            solve(
                nextIndex + 2,
                first
            )
        );

        answer = min(
            answer,
            max(
                nums[first],
                nums[third]
            ) +
            solve(
                nextIndex + 2,
                second
            )
        );

        answer = min(
            answer,
            max(
                nums[first],
                nums[second]
            ) +
            solve(
                nextIndex + 2,
                third
            )
        );

        memo[nextIndex][carried] =
            answer;

        return answer;
    }

public:
    int minCost(vector<int>& input) {
        nums =
            input;

        int n =
            static_cast<int>(nums.size());

        if (n < 3) {
            return *max_element(
                nums.begin(),
                nums.end()
            );
        }

        memo.assign(
            n + 1,
            vector<int>(
                n,
                0
            )
        );

        visited.assign(
            n + 1,
            vector<bool>(
                n,
                false
            )
        );

        return solve(
            1,
            0
        );
    }
};
