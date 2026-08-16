class Solution {
public:
    vector<int> goodDaysToRobBank(
        vector<int>& security,
        int time
    ) {
        int n =
            static_cast<int>(security.size());

        vector<int> answer;

        for (int day = 0; day < n; day++) {
            if (day - time < 0 ||
                day + time >= n) {
                continue;
            }

            bool valid = true;

            for (int index = day - time + 1;
                 index <= day;
                 index++) {
                if (security[index] >
                    security[index - 1]) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                continue;
            }

            for (int index = day + 1;
                 index <= day + time;
                 index++) {
                if (security[index] <
                    security[index - 1]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                answer.push_back(day);
            }
        }

        return answer;
    }
};
