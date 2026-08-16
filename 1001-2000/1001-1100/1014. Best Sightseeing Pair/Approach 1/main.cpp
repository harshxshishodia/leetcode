class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int answer =
            numeric_limits<int>::min();

        for (int i = 0;
             i < static_cast<int>(values.size());
             i++) {
            for (int j = i + 1;
                 j < static_cast<int>(values.size());
                 j++) {
                answer = max(
                    answer,
                    values[i] +
                    values[j] +
                    i -
                    j
                );
            }
        }

        return answer;
    }
};
