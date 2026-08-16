class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        vector<int> maximumPrefix(
            n
        );

        vector<int> maximumSuffix(
            n
        );

        int prefixSum = 0;
        int suffixSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            maximumPrefix[i] =
                i == 0
                    ? prefixSum
                    : max(
                        maximumPrefix[i - 1],
                        prefixSum
                    );

            suffixSum +=
                nums[n - 1 - i];

            maximumSuffix[n - 1 - i] =
                i == 0
                    ? suffixSum
                    : max(
                        maximumSuffix[n - i],
                        suffixSum
                    );
        }

        int current = nums[0];
        int answer = nums[0];

        for (int i = 1; i < n; i++) {
            current = max(
                nums[i],
                current + nums[i]
            );

            answer = max(
                answer,
                current
            );
        }

        for (int split = 0;
             split + 1 < n;
             split++) {
            answer = max(
                answer,
                maximumPrefix[split] +
                maximumSuffix[split + 1]
            );
        }

        return answer;
    }
};
