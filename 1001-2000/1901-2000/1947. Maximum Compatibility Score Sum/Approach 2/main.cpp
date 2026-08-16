class Solution {
    vector<vector<int>> score;
    int answer = 0;

    void search(
        int student,
        int current,
        vector<bool>& used
    ) {
        if (student ==
            static_cast<int>(score.size())) {
            answer = max(
                answer,
                current
            );

            return;
        }

        for (int mentor = 0;
             mentor < static_cast<int>(score.size());
             mentor++) {
            if (used[mentor]) {
                continue;
            }

            used[mentor] = true;

            search(
                student + 1,
                current +
                score[student][mentor],
                used
            );

            used[mentor] = false;
        }
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

        answer = 0;
        vector<bool> used(count);

        search(
            0,
            0,
            used
        );

        return answer;
    }
};
