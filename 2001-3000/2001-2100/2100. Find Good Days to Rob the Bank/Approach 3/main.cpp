class Solution {
public:
    vector<int> goodDaysToRobBank(
        vector<int>& security,
        int time
    ) {
        int n =
            static_cast<int>(security.size());

        vector<int> nonIncreasing(n);
        vector<int> nonDecreasing(n);

        for (int index = 1; index < n; index++) {
            if (security[index] <=
                security[index - 1]) {
                nonIncreasing[index] =
                    nonIncreasing[index - 1] +
                    1;
            }
        }

        for (int index = n - 2; index >= 0; index--) {
            if (security[index] <=
                security[index + 1]) {
                nonDecreasing[index] =
                    nonDecreasing[index + 1] +
                    1;
            }
        }

        vector<int> answer;

        for (int day = 0; day < n; day++) {
            if (nonIncreasing[day] >= time &&
                nonDecreasing[day] >= time) {
                answer.push_back(day);
            }
        }

        return answer;
    }
};
