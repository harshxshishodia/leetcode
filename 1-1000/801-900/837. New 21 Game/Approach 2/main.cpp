class Solution {
    vector<double> memo;
    vector<bool> visited;

    double solve(
        int score,
        int n,
        int k,
        int maxPts
    ) {
        if (score >= k) {
            return score <= n ? 1.0 : 0.0;
        }

        if (visited[score]) {
            return memo[score];
        }

        visited[score] = true;

        double probability = 0.0;

        for (int points = 1; points <= maxPts; points++) {
            probability +=
                solve(
                    score + points,
                    n,
                    k,
                    maxPts
                ) /
                maxPts;
        }

        memo[score] = probability;
        return memo[score];
    }

public:
    double new21Game(int n, int k, int maxPts) {
        memo.assign(
            k,
            0.0
        );

        visited.assign(
            k,
            false
        );

        return solve(
            0,
            n,
            k,
            maxPts
        );
    }
};
