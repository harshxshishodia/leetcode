class Solution {
public:
    vector<int> goodDaysToRobBank(
        vector<int>& security,
        int time
    ) {
        int n =
            static_cast<int>(security.size());

        vector<int> increasePrefix(
            n
        );

        vector<int> decreasePrefix(
            n
        );

        for (int index = 1; index < n; index++) {
            increasePrefix[index] =
                increasePrefix[index - 1] +
                (
                    security[index] >
                    security[index - 1]
                );

            decreasePrefix[index] =
                decreasePrefix[index - 1] +
                (
                    security[index] <
                    security[index - 1]
                );
        }

        vector<int> answer;

        for (int day = time;
             day + time < n;
             day++) {
            int increasesBefore =
                increasePrefix[day] -
                increasePrefix[day - time];

            int decreasesAfter =
                decreasePrefix[day + time] -
                decreasePrefix[day];

            if (increasesBefore == 0 &&
                decreasesAfter == 0) {
                answer.push_back(day);
            }
        }

        return answer;
    }
};
