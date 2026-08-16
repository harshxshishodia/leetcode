class Solution {
    vector<array<int, 27>> memo;
    vector<array<bool, 27>> visited;

    int solve(
        const string& colors,
        const vector<int>& neededTime,
        int index,
        int lastColor
    ) {
        if (index == static_cast<int>(colors.size())) {
            return 0;
        }

        if (visited[index][lastColor]) {
            return memo[index][lastColor];
        }

        visited[index][lastColor] = true;

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

        memo[index][lastColor] = min(
            remove,
            keep
        );

        return memo[index][lastColor];
    }

public:
    int minCost(
        string colors,
        vector<int>& neededTime
    ) {
        memo.assign(
            colors.size(),
            {}
        );

        visited.assign(
            colors.size(),
            {}
        );

        return solve(
            colors,
            neededTime,
            0,
            26
        );
    }
};
