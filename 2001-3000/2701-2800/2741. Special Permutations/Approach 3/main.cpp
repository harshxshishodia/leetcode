class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> nums;
    vector<vector<int>> memo;

    int solve(
        int mask,
        int last
    ) {
        if (mask ==
            (1 << nums.size()) - 1) {
            return 1;
        }

        if (memo[mask][last] != -1) {
            return memo[mask][last];
        }

        long long answer = 0;

        for (int next = 0;
             next < static_cast<int>(nums.size());
             next++) {
            if ((mask & (1 << next)) != 0) {
                continue;
            }

            if (nums[last] % nums[next] != 0 &&
                nums[next] % nums[last] != 0) {
                continue;
            }

            answer +=
                solve(
                    mask |
                    (1 << next),
                    next
                );

            answer %=
                MOD;
        }

        memo[mask][last] =
            static_cast<int>(answer);

        return memo[mask][last];
    }

public:
    int specialPerm(vector<int>& input) {
        nums =
            input;

        int n =
            static_cast<int>(nums.size());

        memo.assign(
            1 << n,
            vector<int>(
                n,
                -1
            )
        );

        long long answer = 0;

        for (int start = 0;
             start < n;
             start++) {
            answer +=
                solve(
                    1 << start,
                    start
                );

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
