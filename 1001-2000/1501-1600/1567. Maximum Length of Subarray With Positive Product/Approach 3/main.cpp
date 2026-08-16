class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positive = 0;
        int negative = 0;
        int answer = 0;

        for (int value : nums) {
            if (value == 0) {
                positive = 0;
                negative = 0;
            } else if (value > 0) {
                positive++;
                negative =
                    negative == 0
                        ? 0
                        : negative + 1;
            } else {
                int previousPositive =
                    positive;

                positive =
                    negative == 0
                        ? 0
                        : negative + 1;

                negative =
                    previousPositive + 1;
            }

            answer = max(
                answer,
                positive
            );
        }

        return answer;
    }
};
