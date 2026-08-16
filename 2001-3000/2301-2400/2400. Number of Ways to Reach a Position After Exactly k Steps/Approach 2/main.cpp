class Solution {
    static constexpr int MOD =
        1000000007;

    vector<vector<int>> memo;
    int offset;

    int solve(
        int position,
        int endPos,
        int steps
    ) {
        if (steps == 0) {
            return position ==
                   endPos;
        }

        int index =
            position +
            offset;

        if (memo[steps][index] != -1) {
            return memo[steps][index];
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

        memo[steps][index] =
            static_cast<int>(
                answer %
                MOD
            );

        return memo[steps][index];
    }

public:
    int numberOfWays(
        int startPos,
        int endPos,
        int k
    ) {
        offset =
            k -
            startPos +
            2;

        int width =
            2 *
            k +
            5;

        memo.assign(
            k + 1,
            vector<int>(
                width,
                -1
            )
        );

        return solve(
            startPos,
            endPos,
            k
        );
    }
};
