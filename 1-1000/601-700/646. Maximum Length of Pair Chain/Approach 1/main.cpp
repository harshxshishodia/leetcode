class Solution {
    int solve(
        const vector<vector<int>>& pairs,
        int index,
        int previousIndex
    ) {
        if (index == static_cast<int>(pairs.size())) {
            return 0;
        }

        int skip = solve(
            pairs,
            index + 1,
            previousIndex
        );

        int take = 0;

        if (previousIndex == -1 ||
            pairs[previousIndex][1] < pairs[index][0]) {
            take = 1 + solve(
                pairs,
                index + 1,
                index
            );
        }

        return max(skip, take);
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(
            pairs.begin(),
            pairs.end()
        );

        return solve(pairs, 0, -1);
    }
};
