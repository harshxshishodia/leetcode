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

        vector<int> bestFirstLeft(
            n + 1
        );

        vector<int> bestSecondLeft(
            n + 1
        );

        for (int end = 1; end <= n; end++) {
            bestFirstLeft[end] =
                bestFirstLeft[end - 1];

            bestSecondLeft[end] =
                bestSecondLeft[end - 1];

            if (end >= firstLen) {
                bestFirstLeft[end] = max(
                    bestFirstLeft[end],
                    prefix[end] -
                    prefix[end - firstLen]
                );
            }

            if (end >= secondLen) {
                bestSecondLeft[end] = max(
                    bestSecondLeft[end],
                    prefix[end] -
                    prefix[end - secondLen]
                );
            }
        }

        int answer = 0;

        for (int start = 0; start <= n; start++) {
            if (start + secondLen <= n) {
                int secondSum =
                    prefix[start + secondLen] -
                    prefix[start];

                answer = max(
                    answer,
                    bestFirstLeft[start] +
                    secondSum
                );
            }

            if (start + firstLen <= n) {
                int firstSum =
                    prefix[start + firstLen] -
                    prefix[start];

                answer = max(
                    answer,
                    bestSecondLeft[start] +
                    firstSum
                );
            }
        }

        return answer;
    }
};
