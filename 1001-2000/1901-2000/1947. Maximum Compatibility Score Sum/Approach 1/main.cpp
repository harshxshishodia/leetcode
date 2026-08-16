class Solution {
    int compatibility(
        const vector<int>& student,
        const vector<int>& mentor
    ) {
        int score = 0;

        for (int question = 0;
             question < static_cast<int>(student.size());
             question++) {
            score +=
                student[question] ==
                mentor[question];
        }

        return score;
    }

public:
    int maxCompatibilitySum(
        vector<vector<int>>& students,
        vector<vector<int>>& mentors
    ) {
        int count =
            static_cast<int>(students.size());

        vector<int> order(count);

        iota(
            order.begin(),
            order.end(),
            0
        );

        int answer = 0;

        do {
            int score = 0;

            for (int student = 0;
                 student < count;
                 student++) {
                score +=
                    compatibility(
                        students[student],
                        mentors[order[student]]
                    );
            }

            answer = max(
                answer,
                score
            );
        } while (next_permutation(
            order.begin(),
            order.end()
        ));

        return answer;
    }
};
