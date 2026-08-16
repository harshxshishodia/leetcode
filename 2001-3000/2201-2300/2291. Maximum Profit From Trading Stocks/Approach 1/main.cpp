class Solution {
    int solve(
        const vector<int>& present,
        const vector<int>& future,
        int index,
        int budget
    ) {
        if (index ==
            static_cast<int>(present.size())) {
            return 0;
        }

        int skip =
            solve(
                present,
                future,
                index + 1,
                budget
            );

        int take = 0;

        if (present[index] <= budget) {
            take =
                future[index] -
                present[index] +
                solve(
                    present,
                    future,
                    index + 1,
                    budget -
                    present[index]
                );
        }

        return max(
            skip,
            take
        );
    }

public:
    int maximumProfit(
        vector<int>& present,
        vector<int>& future,
        int budget
    ) {
        return solve(
            present,
            future,
            0,
            budget
        );
    }
};
