class Solution {
    static constexpr int MOD = 1000000007;

    int solve(
        int dice,
        int faces,
        int target,
        vector<vector<int>>& memo
    ) {
        if (dice == 0) {
            return target == 0;
        }

        if (target <= 0) {
            return 0;
        }

        if (memo[dice][target] != -1) {
            return memo[dice][target];
        }

        long long answer = 0;

        for (int face = 1;
             face <= faces &&
             face <= target;
             face++) {
            answer += solve(
                dice - 1,
                faces,
                target - face,
                memo
            );

            answer %= MOD;
        }

        memo[dice][target] =
            static_cast<int>(answer);

        return memo[dice][target];
    }

public:
    int numRollsToTarget(
        int n,
        int k,
        int target
    ) {
        vector<vector<int>> memo(
            n + 1,
            vector<int>(
                target + 1,
                -1
            )
        );

        return solve(
            n,
            k,
            target,
            memo
        );
    }
};
