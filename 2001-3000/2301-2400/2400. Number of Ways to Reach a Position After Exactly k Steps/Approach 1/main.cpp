class Solution {
    static constexpr int MOD =
        1000000007;

    int solve(
        int position,
        int endPos,
        int steps
    ) {
        if (steps == 0) {
            return position ==
                   endPos;
        }

        long long answer =
            solve(
                position - 1,
                endPos,
                steps - 1
            );

        answer +=
            solve(
                position + 1,
                endPos,
                steps - 1
            );

        return static_cast<int>(
            answer % MOD
        );
    }

public:
    int numberOfWays(
        int startPos,
        int endPos,
        int k
    ) {
        return solve(
            startPos,
            endPos,
            k
        );
    }
};
