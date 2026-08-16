class Solution {
public:
    int maxSumTwoNoOverlap(
        vector<int>& nums,
        int firstLen,
        int secondLen
    ) {
        int n = static_cast<int>(nums.size());
        int answer = 0;

        for (int firstStart = 0;
             firstStart + firstLen <= n;
             firstStart++) {
            int firstSum = 0;

            for (int i = firstStart;
                 i < firstStart + firstLen;
                 i++) {
                firstSum += nums[i];
            }

            for (int secondStart = 0;
                 secondStart + secondLen <= n;
                 secondStart++) {
                int firstEnd =
                    firstStart +
                    firstLen -
                    1;

                int secondEnd =
                    secondStart +
                    secondLen -
                    1;

                if (max(
                        firstStart,
                        secondStart) <=
                    min(
                        firstEnd,
                        secondEnd)) {
                    continue;
                }

                int secondSum = 0;

                for (int i = secondStart;
                     i < secondStart + secondLen;
                     i++) {
                    secondSum += nums[i];
                }

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
