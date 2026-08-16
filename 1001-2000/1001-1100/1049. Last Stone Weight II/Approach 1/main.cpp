class Solution {
    int solve(
        const vector<int>& stones,
        int index,
        int difference
    ) {
        if (index == static_cast<int>(stones.size())) {
            return abs(difference);
        }

        return min(
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
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        return solve(
            stones,
            0,
            0
        );
    }
};
