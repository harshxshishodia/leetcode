class Solution {
public:
    int maxCompatibilitySum(
        vector<vector<int>>& students,
        vector<vector<int>>& mentors
    ) {
        int count =
            static_cast<int>(students.size());

        vector<vector<int>> score(
            count,
            vector<int>(count)
        );

        for (int student = 0; student < count; student++) {
            for (int mentor = 0; mentor < count; mentor++) {
                for (int question = 0;
                     question < static_cast<int>(students[0].size());
                     question++) {
                    score[student][mentor] +=
                        students[student][question] ==
                        mentors[mentor][question];
                }
            }
        }

        int states =
            1 << count;

        vector<int> dp(
            states,
            -1
        );

        dp[0] = 0;

        for (int mask = 0; mask < states; mask++) {
            if (dp[mask] == -1) {
                continue;
            }

            int student =
                __builtin_popcount(
                    static_cast<unsigned int>(mask)
                );

            if (student == count) {
                continue;
            }

            for (int mentor = 0; mentor < count; mentor++) {
                int bit =
                    1 << mentor;

                if ((mask & bit) != 0) {
                    continue;
                }

                dp[mask | bit] = max(
                    dp[mask | bit],
                    dp[mask] +
                    score[student][mentor]
                );
            }
        }

        return dp[states - 1];
    }
};
