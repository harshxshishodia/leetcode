class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = static_cast<int>(values.size());

        vector<int> bestLeft(n);
        bestLeft[0] = values[0];

        for (int i = 1; i < n; i++) {
            bestLeft[i] = max(
                bestLeft[i - 1],
                values[i] + i
            );
        }

        int answer =
            numeric_limits<int>::min();

        for (int j = 1; j < n; j++) {
            answer = max(
                answer,
                bestLeft[j - 1] +
                values[j] -
                j
            );
        }

        return answer;
    }
};
