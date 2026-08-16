class Solution {
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

        return
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
    }

public:
    double probabilityOfHeads(
        vector<double>& prob,
        int target
    ) {
        return solve(
            prob,
            0,
            target
        );
    }
};
