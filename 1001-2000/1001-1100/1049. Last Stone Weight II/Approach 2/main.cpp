class Solution {
    int total;
    vector<vector<int>> memo;

    int solve(
        const vector<int>& stones,
        int index,
        int difference
    ) {
        if (index == static_cast<int>(stones.size())) {
            return abs(difference);
        }

        int state =
            difference +
            total;

        if (memo[index][state] != -1) {
            return memo[index][state];
        }

        memo[index][state] = min(
            solve(
                stones,
                index + 1,
                difference + stones[index]
            ),
            solve(
                stones,
                index + 1,
                difference - stones[index]
            )
        );

        return memo[index][state];
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        total = accumulate(
            stones.begin(),
            stones.end(),
            0
        );

        memo.assign(
            stones.size(),
            vector<int>(
                2 * total + 1,
                -1
            )
        );

        return solve(
            stones,
            0,
            0
        );
    }
};
