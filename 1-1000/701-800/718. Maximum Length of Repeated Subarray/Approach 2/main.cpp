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
                1 + solve(
                    first,
                    second,
                    i + 1,
                    j + 1,
                    memo
                );
        } else {
            memo[i][j] = 0;
        }

        return memo[i][j];
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> memo(
            nums1.size(),
            vector<int>(nums2.size(), -1)
        );

        int answer = 0;

        for (int i = 0; i < static_cast<int>(nums1.size()); i++) {
            for (int j = 0; j < static_cast<int>(nums2.size()); j++) {
                answer = max(
                    answer,
                    solve(
                        nums1,
                        nums2,
                        i,
                        j,
                        memo
                    )
                );
            }
        }

        return answer;
    }
};
