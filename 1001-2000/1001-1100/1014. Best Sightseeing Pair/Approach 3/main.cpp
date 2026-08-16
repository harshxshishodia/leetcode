class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int bestLeft =
            values[0];

        int answer =
            numeric_limits<int>::min();

        for (int j = 1;
             j < static_cast<int>(values.size());
             j++) {
            answer = max(
                answer,
                bestLeft +
                values[j] -
                j
            );

            bestLeft = max(
                bestLeft,
                values[j] + j
            );
        }

        return answer;
    }
};
