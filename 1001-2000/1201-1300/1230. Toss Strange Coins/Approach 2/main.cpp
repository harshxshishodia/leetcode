class Solution {
    vector<vector<double>> memo;
    vector<vector<bool>> visited;

    double solve(
        const vector<double>& prob,
        int index,
        int heads
    ) {
        if (index == static_cast<int>(prob.size())) {
            return heads == 0
                ? 1.0
                : 0.0;
        }

        if (heads < 0) {
            return 0.0;
        }

        if (visited[index][heads]) {
            return memo[index][heads];
        }

        visited[index][heads] = true;

        memo[index][heads] =
            prob[index] *
            solve(
                prob,
                index + 1,
                heads - 1
            ) +
            (1.0 - prob[index]) *
            solve(
                prob,
                index + 1,
                heads
            );

        return memo[index][heads];
    }

public:
    double probabilityOfHeads(
        vector<double>& prob,
        int target
    ) {
        memo.assign(
            prob.size(),
            vector<double>(
                target + 1
            )
        );

        visited.assign(
            prob.size(),
            vector<bool>(
                target + 1
            )
        );

        return solve(
            prob,
            0,
            target
        );
    }
};
