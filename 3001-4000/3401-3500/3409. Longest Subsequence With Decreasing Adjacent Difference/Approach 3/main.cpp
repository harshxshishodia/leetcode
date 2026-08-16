class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int MAX_VALUE =
            300;

        const int MAX_DIFF =
            300;

        vector<array<int, MAX_DIFF + 1>> exact(
            MAX_VALUE + 1
        );

        vector<array<int, MAX_DIFF + 2>> suffix(
            MAX_VALUE + 1
        );

        array<bool, MAX_VALUE + 1> seen = {};

        int answer = 1;

        for (int value :
             nums) {
            array<int, MAX_DIFF + 1> candidate = {};

            for (int previous = 1;
                 previous <= MAX_VALUE;
                 previous++) {
                if (!seen[previous]) {
                    continue;
                }

                int difference =
                    abs(
                        value -
                        previous
                    );

                candidate[difference] = max(
                    candidate[difference],
                    max(
                        2,
                        suffix[previous][difference] +
                        1
                    )
                );
            }

            for (int difference = 0;
                 difference <= MAX_DIFF;
                 difference++) {
                exact[value][difference] = max(
                    exact[value][difference],
                    candidate[difference]
                );
            }

            suffix[value][MAX_DIFF + 1] =
                0;

            for (int difference = MAX_DIFF;
                 difference >= 0;
                 difference--) {
                suffix[value][difference] = max(
                    exact[value][difference],
                    suffix[value][difference + 1]
                );
            }

            seen[value] =
                true;

            answer = max(
                answer,
                suffix[value][0]
            );
        }

        return answer;
    }
};
