class Solution {
    vector<int> suffixFirst;
    vector<int> suffixSecond;

    int solve(
        const string& first,
        const string& second,
        int i,
        int j,
        vector<vector<int>>& memo
    ) {
        if (i == static_cast<int>(first.size())) {
            return suffixSecond[j];
        }

        if (j == static_cast<int>(second.size())) {
            return suffixFirst[i];
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (first[i] == second[j]) {
            memo[i][j] = solve(
                first,
                second,
                i + 1,
                j + 1,
                memo
            );
        } else {
            memo[i][j] = min(
                static_cast<unsigned char>(first[i]) +
                solve(
                    first,
                    second,
                    i + 1,
                    j,
                    memo
                ),
                static_cast<unsigned char>(second[j]) +
                solve(
                    first,
                    second,
                    i,
                    j + 1,
                    memo
                )
            );
        }

        return memo[i][j];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        suffixFirst.assign(
            s1.size() + 1,
            0
        );

        suffixSecond.assign(
            s2.size() + 1,
            0
        );

        for (int i = static_cast<int>(s1.size()) - 1; i >= 0; i--) {
            suffixFirst[i] =
                suffixFirst[i + 1] +
                static_cast<unsigned char>(s1[i]);
        }

        for (int j = static_cast<int>(s2.size()) - 1; j >= 0; j--) {
            suffixSecond[j] =
                suffixSecond[j + 1] +
                static_cast<unsigned char>(s2[j]);
        }

        vector<vector<int>> memo(
            s1.size(),
            vector<int>(s2.size(), -1)
        );

        return solve(
            s1,
            s2,
            0,
            0,
            memo
        );
    }
};
