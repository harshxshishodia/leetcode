class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<vector<int>> lcp(
            n + 1,
            vector<int>(
                n + 1
            )
        );

        for (int first = n - 1;
             first >= 0;
             first--) {
            for (int second = n - 1;
                 second > first;
                 second--) {
                if (nums[first] ==
                    nums[second]) {
                    lcp[first][second] =
                        1 +
                        lcp[first + 1][second + 1];
                }
            }
        }

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
                    firstLength <=
                        secondLength &&
                    lcp[0][firstEnd] >=
                        firstLength;

                bool secondCondition =
                    secondLength <=
                        thirdLength &&
                    lcp[firstEnd][secondEnd] >=
                        secondLength;

                answer +=
                    firstCondition ||
                    secondCondition;
            }
        }

        return answer;
    }
};
