class Solution {
    int bestOrder(
        const vector<int>& prefix,
        int firstLen,
        int secondLen
    ) {
        int n =
            static_cast<int>(prefix.size()) -
            1;

        int bestFirst = 0;
        int answer = 0;

        for (int end = firstLen + secondLen;
             end <= n;
             end++) {
            bestFirst = max(
                bestFirst,
                prefix[end - secondLen] -
                prefix[end - secondLen - firstLen]
            );

            int secondSum =
                prefix[end] -
                prefix[end - secondLen];

            answer = max(
                answer,
                bestFirst +
                secondSum
            );
        }

        return answer;
    }

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

        return max(
            bestOrder(
                prefix,
                firstLen,
                secondLen
            ),
            bestOrder(
                prefix,
                secondLen,
                firstLen
            )
        );
    }
};
