class Solution {
    static constexpr int MOD = 1000000007;

    int solve(
        int dice,
        int faces,
        int target
    ) {
        if (dice == 0) {
            return target == 0;
        }

        if (target <= 0) {
            return 0;
        }

        long long answer = 0;

        for (int face = 1; face <= faces; face++) {
            answer += solve(
                dice - 1,
                faces,
                target - face
            );

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }

public:
    int numRollsToTarget(
        int n,
        int k,
        int target
    ) {
        return solve(
            n,
            k,
            target
        );
    }
};
