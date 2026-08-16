class Solution {
    vector<vector<int>> memo;

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

        if (memo[index][budget] != -1) {
            return memo[index][budget];
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

        memo[index][budget] = max(
            skip,
            take
        );

        return memo[index][budget];
    }

public:
    int maximumProfit(
        vector<int>& present,
        vector<int>& future,
        int budget
    ) {
        memo.assign(
            present.size(),
            vector<int>(
                budget + 1,
                -1
            )
        );

        return solve(
            present,
            future,
            0,
            budget
        );
    }
};
