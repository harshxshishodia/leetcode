class Solution {
    int solve(
        const vector<vector<int>>& pairs,
        int index,
        int previousIndex,
        vector<vector<int>>& memo
    ) {
        if (index == static_cast<int>(pairs.size())) {
            return 0;
        }

        int previousState = previousIndex + 1;

        if (memo[index][previousState] != -1) {
            return memo[index][previousState];
        }

        int skip = solve(
            pairs,
            index + 1,
            previousIndex,
            memo
        );

        int take = 0;

        if (previousIndex == -1 ||
            pairs[previousIndex][1] < pairs[index][0]) {
            take = 1 + solve(
                pairs,
                index + 1,
                index,
                memo
            );
        }

        memo[index][previousState] = max(skip, take);
        return memo[index][previousState];
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(
            pairs.begin(),
            pairs.end()
        );

        int n = static_cast<int>(pairs.size());

        vector<vector<int>> memo(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(pairs, 0, -1, memo);
    }
};
