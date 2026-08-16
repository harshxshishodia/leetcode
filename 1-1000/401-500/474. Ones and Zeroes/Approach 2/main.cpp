class Solution {
    vector<pair<int, int>> counts;

    int solve(
        int index,
        int zeroes,
        int ones,
        vector<vector<vector<int>>>& memo
    ) {
        if (index == static_cast<int>(counts.size())) {
            return 0;
        }

        if (memo[index][zeroes][ones] != -1) {
            return memo[index][zeroes][ones];
        }

        int skip = solve(
            index + 1,
            zeroes,
            ones,
            memo
        );

        int take = 0;
        auto [neededZeroes, neededOnes] = counts[index];

        if (neededZeroes <= zeroes &&
            neededOnes <= ones) {
            take = 1 + solve(
                index + 1,
                zeroes - neededZeroes,
                ones - neededOnes,
                memo
            );
        }

        memo[index][zeroes][ones] = max(skip, take);
        return memo[index][zeroes][ones];
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        counts.clear();

        for (const string& s : strs) {
            int zeroes = 0;
            int ones = 0;

            for (char character : s) {
                if (character == '0') {
                    zeroes++;
                } else {
                    ones++;
                }
            }

            counts.push_back({zeroes, ones});
        }

        vector<vector<vector<int>>> memo(
            strs.size(),
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );

        return solve(0, m, n, memo);
    }
};
