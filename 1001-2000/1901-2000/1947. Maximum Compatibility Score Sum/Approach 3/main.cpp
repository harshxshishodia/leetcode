class Solution {
    vector<vector<int>> score;
    vector<int> memo;

    int solve(int mask) {
        int student =
            __builtin_popcount(
                static_cast<unsigned int>(mask)
            );

        if (student ==
            static_cast<int>(score.size())) {
            return 0;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        int answer = 0;

        for (int mentor = 0;
             mentor < static_cast<int>(score.size());
             mentor++) {
            int bit =
                1 << mentor;

            if ((mask & bit) != 0) {
                continue;
            }

            answer = max(
                answer,
                score[student][mentor] +
                solve(
                    mask | bit
                )
            );
        }

        memo[mask] = answer;
        return memo[mask];
    }

public:
    int maxCompatibilitySum(
        vector<vector<int>>& students,
        vector<vector<int>>& mentors
    ) {
        int count =
            static_cast<int>(students.size());

        score.assign(
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

        memo.assign(
            1 << count,
            -1
        );

        return solve(0);
    }
};
