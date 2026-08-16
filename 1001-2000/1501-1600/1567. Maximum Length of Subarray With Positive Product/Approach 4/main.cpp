class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int answer = 0;
        int start = 0;
        int firstNegative = -1;
        int lastNegative = -1;
        int negativeCount = 0;

        for (int i = 0; i <= static_cast<int>(nums.size()); i++) {
            if (i < static_cast<int>(nums.size()) &&
                nums[i] != 0) {
                if (nums[i] < 0) {
                    negativeCount++;

                    if (firstNegative == -1) {
                        firstNegative = i;
                    }

                    lastNegative = i;
                }

                continue;
            }

            int end = i;

            if (negativeCount % 2 == 0) {
                answer = max(
                    answer,
                    end - start
                );
            } else {
                answer = max(
                    answer,
                    end - firstNegative - 1
                );

                answer = max(
                    answer,
                    lastNegative - start
                );
            }

            start = i + 1;
            firstNegative = -1;
            lastNegative = -1;
            negativeCount = 0;
        }

        return answer;
    }
};
