class Solution {
public:
    int maxSumTwoNoOverlap(
        vector<int>& nums,
        int firstLen,
        int secondLen
    ) {
        int n = static_cast<int>(nums.size());

        vector<int> prefix(
            n + 1
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                nums[i];
        }

        int answer = 0;

        for (int firstStart = 0;
             firstStart + firstLen <= n;
             firstStart++) {
            int firstEnd =
                firstStart +
                firstLen;

            int firstSum =
                prefix[firstEnd] -
                prefix[firstStart];

            for (int secondStart = 0;
                 secondStart + secondLen <= n;
                 secondStart++) {
                int secondEnd =
                    secondStart +
                    secondLen;

                if (max(
                        firstStart,
                        secondStart) <
                    min(
                        firstEnd,
                        secondEnd)) {
                    continue;
                }

                int secondSum =
                    prefix[secondEnd] -
                    prefix[secondStart];

                answer = max(
                    answer,
                    firstSum +
                    secondSum
                );
            }
        }

        return answer;
    }
};
