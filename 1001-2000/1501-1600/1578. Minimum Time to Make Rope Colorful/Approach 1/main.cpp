class Solution {
    int solve(
        const string& colors,
        const vector<int>& neededTime,
        int index,
        int lastColor
    ) {
        if (index == static_cast<int>(colors.size())) {
            return 0;
        }

        int currentColor =
            colors[index] - 'a';

        int remove =
            neededTime[index] +
            solve(
                colors,
                neededTime,
                index + 1,
                lastColor
            );

        int keep =
            numeric_limits<int>::max() / 4;

        if (currentColor != lastColor) {
            keep = solve(
                colors,
                neededTime,
                index + 1,
                currentColor
            );
        }

        return min(
            remove,
            keep
        );
    }

public:
    int minCost(
        string colors,
        vector<int>& neededTime
    ) {
        return solve(
            colors,
            neededTime,
            0,
            26
        );
    }
};
