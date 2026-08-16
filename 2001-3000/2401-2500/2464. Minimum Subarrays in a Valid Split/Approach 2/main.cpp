class Solution {
    vector<int> memo;

    int solve(
        const vector<int>& nums,
        int index
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        const int INF =
            1000000000;

        int answer = INF;

        for (int end = index;
             end < n;
             end++) {
            if (gcd(
                    nums[index],
                    nums[end]
                ) <= 1) {
                continue;
            }

            int next =
                solve(
                    nums,
                    end + 1
                );

            if (next != INF) {
                answer = min(
                    answer,
                    1 + next
                );
            }
        }

        memo[index] =
            answer;

        return memo[index];
    }

public:
    int validSubarraySplit(vector<int>& nums) {
        memo.assign(
            nums.size(),
            -1
        );

        const int INF =
            1000000000;

        int answer =
            solve(
                nums,
                0
            );

        return answer == INF
            ? -1
            : answer;
    }
};
