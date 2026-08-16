class Solution {
    int solve(
        const vector<int>& first,
        const vector<int>& second,
        int i,
        int j,
        vector<vector<int>>& memo
    ) {
        if (i == static_cast<int>(first.size()) ||
            j == static_cast<int>(second.size())) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (first[i] == second[j]) {
            memo[i][j] =
                1 +
                solve(
                    first,
                    second,
                    i + 1,
                    j + 1,
                    memo
                );
        } else {
            memo[i][j] = max(
                solve(
                    first,
                    second,
                    i + 1,
                    j,
                    memo
                ),
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
    int maxUncrossedLines(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        vector<vector<int>> memo(
            nums1.size(),
            vector<int>(
                nums2.size(),
                -1
            )
        );

        return solve(
            nums1,
            nums2,
            0,
            0,
            memo
        );
    }
};
