class Solution {
    double solve(
        int score,
        int n,
        int k,
        int maxPts
    ) {
        if (score >= k) {
            return score <= n ? 1.0 : 0.0;
        }

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

        return probability;
    }

public:
    double new21Game(int n, int k, int maxPts) {
        return solve(
            0,
            n,
            k,
            maxPts
        );
    }
};
