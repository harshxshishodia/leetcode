class Solution {
    vector<int> zFunction(
        const vector<int>& values
    ) {
        int n =
            static_cast<int>(values.size());

        vector<int> z(n);

        int left = 0;
        int right = 0;

        for (int index = 1;
             index < n;
             index++) {
            if (index <= right) {
                z[index] = min(
                    right -
                    index +
                    1,
                    z[index - left]
                );
            }

            while (
                index +
                    z[index] <
                    n &&
                values[z[index]] ==
                    values[
                        index +
                        z[index]
                    ]
            ) {
                z[index]++;
            }

            if (
                index +
                    z[index] -
                    1 >
                right
            ) {
                left =
                    index;

                right =
                    index +
                    z[index] -
                    1;
            }
        }

        return z;
    }

public:
    int beautifulSplits(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> wholeZ =
            zFunction(nums);

        int answer = 0;

        for (int firstEnd = 1;
             firstEnd < n - 1;
             firstEnd++) {
            vector<int> suffix(
                nums.begin() +
                    firstEnd,
                nums.end()
            );

            vector<int> suffixZ =
                zFunction(
                    suffix
                );

            for (int secondLength = 1;
                 firstEnd +
                     secondLength <
                     n;
                 secondLength++) {
                int secondEnd =
                    firstEnd +
                    secondLength;

                int thirdLength =
                    n -
                    secondEnd;

                bool firstCondition =
                    firstEnd <=
                        secondLength &&
                    wholeZ[firstEnd] >=
                        firstEnd;

                bool secondCondition =
                    secondLength <=
                        thirdLength &&
                    suffixZ[secondLength] >=
                        secondLength;

                answer +=
                    firstCondition ||
                    secondCondition;
            }
        }

        return answer;
    }
};
