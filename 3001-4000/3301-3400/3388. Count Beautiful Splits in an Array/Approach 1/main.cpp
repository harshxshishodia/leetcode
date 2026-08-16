class Solution {
    bool prefix(
        const vector<int>& nums,
        int firstStart,
        int firstLength,
        int secondStart,
        int secondLength
    ) {
        if (firstLength >
            secondLength) {
            return false;
        }

        for (int offset = 0;
             offset < firstLength;
             offset++) {
            if (
                nums[firstStart + offset] !=
                nums[secondStart + offset]
            ) {
                return false;
            }
        }

        return true;
    }

public:
    int beautifulSplits(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        int answer = 0;

        for (int firstEnd = 1;
             firstEnd < n - 1;
             firstEnd++) {
            for (int secondEnd =
                     firstEnd +
                     1;
                 secondEnd < n;
                 secondEnd++) {
                int firstLength =
                    firstEnd;

                int secondLength =
                    secondEnd -
                    firstEnd;

                int thirdLength =
                    n -
                    secondEnd;

                bool firstCondition =
                    prefix(
                        nums,
                        0,
                        firstLength,
                        firstEnd,
                        secondLength
                    );

                bool secondCondition =
                    prefix(
                        nums,
                        firstEnd,
                        secondLength,
                        secondEnd,
                        thirdLength
                    );

                answer +=
                    firstCondition ||
                    secondCondition;
            }
        }

        return answer;
    }
};
